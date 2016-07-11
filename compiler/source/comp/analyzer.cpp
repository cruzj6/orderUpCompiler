#include "comp/analyzer.h"
#include "comp/stmnt.h"
#include "symbols/env.h"
#include "symbols/type.h"
#include "comp/id.h"
#include "comp/error.h"
#include <sstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>

void Analyzer::setInfilePath(std::string p)
{
  curInFilePath = p;
}

void Analyzer::throwError(std::string msg)
{
  std::stringstream ss;
  ss << msg << " at line " << lexer->curLine << "\n";
  Error* e = new Error();
  e->msg = ss.str();
  throw *e;
}

void Analyzer::program()
{
  used = 0;
  lexer = new Lexer();
  lexer->begin(curInFilePath);
  top = new Env(NULL);
  move();

  Stmnt* s;
  try{
    s = functions(); //Get the syntax/parse tree
  }
  catch(Error e)
  {
    throwError(e.msg);
  }

  #ifdef DEBUG
  s->printNode();
  #endif

  //Tree Cleanup
  delete s;
}

void Analyzer::match(int toMatch)
{
  #ifdef DEBUG
  Token* saveToken = curToken;
  std::cout << "=============Match===========" << std::endl;
  #endif

  if(curToken->tag == -1)
  {
    std::stringstream ss;
    ss << "Unknown token: " << curToken->unknownToken << "\n";
    #ifdef DEBUG
    std::cout << saveToken->getString() << std::endl;
    #endif
    throwError(ss.str());
  }
  else if(curToken->tag == toMatch)
  {
    #ifdef DEBUG
    std::cout << "Good" << std::endl;
    std::cout << saveToken->getString() << std::endl;
    #endif

    move();
  }
  else
  {
    #ifdef DEBUG
    std::cout << saveToken->getString() << std::endl;
    #endif

    std::stringstream ss;
    ss << "Unexpected token: " << curToken->getName() << "\n";
    throwError(ss.str());
  }
  #ifdef DEBUG
  std::cout << "=============================" << std::endl;
  #endif
}

void Analyzer::move()
{
  Token* t = lexer->scan();
  if(t->unknownToken != "")
  {
    std::cout << "Unknown Token" << t->unknownToken << std::endl;
  }
  curToken = t;
}

Stmnt* Analyzer::functions()
{
  //Build globals, these can come before any function
  declarations();
  Stmnt* node;
  if(curToken->tag == ENDOFFILE) return NULL;

  //Create new sequence for each statement, passing it function as statement
  node = new Seq(function(), functions());
  return node;
}

Stmnt* Analyzer::function(){
  std::vector<Id*> params;
  Return::curFuncBlock = NULL;

  //A function should now start
  match(FUNC); //breakfastOrder
  Token* funcTok = curToken;
  match(ID); //func name
  Type* t = NULL;

  //Function scope symbol table to top
  Env* saveTop = top;
  top = new Env(top);
  match(GROUPSTART); //open paren

  //If no close paren yet, this must be declaration for param
  if(curToken->tag != GROUPEND)
  {
    do{
      if(curToken->tag == PARAMSEP) move();
      //Parse the type
      Type* t = type();
      match(ASSIGNTYPE); //@

      //Parse the ID
      Token* idTok = curToken;
      match(ID);

      //Add it to the symbol table
      Id* id = new Id(idTok, t, used);
      top->addSymbol(idTok, id);
      params.push_back(id);
      used = used + t->width;
    } while(curToken->tag == PARAMSEP);

    match(GROUPEND);
  }
  else match(GROUPEND);

  //Do we have a return tag?
  if(curToken->tag == RETTYPE) {
    match(RETTYPE);
    t = type();
  }

  std::vector<Type*> pTypes;
  std::vector<Id*>::iterator it;
  for(it = params.begin(); it != params.end(); it++)
  {
    pTypes.push_back((*it)->type);
    used += (*it)->type->width;
  }

  //Build symbol table entry
  FunctionType* ft = new FunctionType(t, pTypes);
  saveTop->addSymbol(funcTok, new Id(funcTok, ft, used));
  Return::curFuncBlock = saveTop->getIdForToken(funcTok);

  //Start of the function block, do this here to keep symbol table consistent with params
  match(BLOCKSTART);// {
  declarations();
  Stmnt* funcBlock = stmnts(); //List of our statements
  Function* f = new Function(params, funcBlock, t);
  match(BLOCKEND);// }

  top = saveTop;
  return f;
}

Stmnt* Analyzer::block(){
  match(BLOCKSTART);// {
  Env* saveTop = top;
  top = new Env(top);

  //Variable declarations into the symbol tablehhh
  declarations();

  //Stmnts
  Stmnt* st = stmnts(); //List of our statements
  match(BLOCKEND);// }
  Env* tempTop = top;
  top = saveTop;
  return st;
}

Stmnt* Analyzer::stmnts(){
  if(curToken->tag == BLOCKEND)
  {
    return NULL;
  }
  //A statement followed by more statements
  Stmnt* node = new Seq(stmnt(), stmnts());
  return node;
}

/*******EBNF********
 <stmnt> -> orderUp (<expr> | E);
	| id <- <expr>;
	| break;
	| roll(id : (<expr>) -> (<expr>) stepBy (<expr>))<block>
	| fresh(<bool>) <block> [?fresh(<bool>) ]* [expired <block>]
*/
Stmnt* Analyzer::stmnt(){
  if(curToken->tag == FOR)
  {
    move();
    match(GROUPSTART);
    Token* tok = curToken;
    match(ID);//counter

    //Get the identifier for the counter
    Id* c = top->getIdForToken(tok);
    if(top == NULL) //Never declared
    {
      Word* w = (Word*)curToken;
      if(w != NULL)
      {
        std::string l = w->lexeme;
        std::cout << "ERROR: identifier " << l
        << " never declared!";
      }
    }
    Roll* loop = new Roll();
    Stmnt* saveEnc = Stmnt::Enclosing;
    Stmnt::Enclosing = loop;
    match(ASEP); // :
    Expr* num1 = expr();
    match(FLOW); // ->
    Expr* num2 = expr();
    if(curToken->tag != STEP)
    {
      throwError("Loops require \"stepBy\" loop incrementation");
    }
    match(STEP);
    Expr* step = expr();
    match(GROUPEND);
    Stmnt* b = stmnt();
    loop->init(c, num1, num2, step, b);
    Stmnt::Enclosing = saveEnc;
    return loop;
   }
   else if(curToken->tag == IF)
   {
     move();
     match(GROUPSTART);
     Expr* cond = expr(); //T/F Condition
     match(GROUPEND);
     Stmnt* st = stmnt(); //The block
     Stmnt* elseChain = Else(); //ifelse to else chain
     return new Fresh(cond, st, elseChain);
   }
   else if(curToken->tag == BLOCKSTART)
   {
     return block();
   }
   else if(curToken->tag == BREAK)
   {
      match(BREAK);
      match(LINEEND);
      return new Break();
   }
   else if(curToken->tag == RETSTMNT)
   {
     //Return from function tag
     match(RETSTMNT);
     //Line end, this means void retuen
     if(curToken->tag == LINEEND) {
       match(LINEEND);
       return new Return(NULL);
     }
     Expr* retStmnt = expr();
     match(LINEEND);
     return new Return(retStmnt);
   }
   else if(curToken->tag == OUT)
   {
     //Print to stdout built in function tag
     match(OUT);
     match(GROUPSTART);
     Expr* e = expr();
     match(GROUPEND);
     match(LINEEND);
     return new ServeOut(e);
   }
   else if(curToken->tag == BASICTYPE)
   {
     declaration();
     match(LINEEND);
     return stmnt();
   }
   else //Assume assignment statement
   {
     Id* id = top->getIdForToken(curToken);
     //Declared?
     if(id == NULL)
     {
       std::stringstream ss;
       ss << "Identifier never declared: " << curToken->getName() << "\n";
       throwError(ss.str());
     }
     match(ID);
     //<-
     if(curToken->tag == ASSIGN){
       match(ASSIGN);
       Expr* val = expr();
       match(LINEEND);
       Assign* a = new Assign(id, val);
       return a;
     }
     //If this is meant to be a function call
     if(curToken->tag == GROUPSTART)
     {
       move();
       std::vector<Expr*> params;
       if(curToken->tag != GROUPEND)
       {
         do{
           if(curToken->tag == PARAMSEP) move();
           params.push_back(expr());
         }while(curToken->tag == PARAMSEP);
       }
       match(GROUPEND);
       match(LINEEND);

       //Get id from table
       Id* func = top->getIdForToken(id->getToken());
       if(func == NULL)
         throwError("Function never declared!");

       Expr* fc =
        new FunctionCall(id->getToken(), id->type, params, func);
        FunctionStmnt* fs = new FunctionStmnt(fc);
        return fs;
     }
     else{
      ArrayAccess* aa = offset(id);
      match(ASSIGN);
      AssignElem* a = new AssignElem(aa, expr());
      match(LINEEND);
      return a;
     }
   }
   return NULL;
}

//Recursively create the chain of else if's to else's
Stmnt* Analyzer::Else()
{
  Stmnt* elseSt = NULL;
  if(curToken->tag == ELSEIF){
    move();
    match(GROUPSTART);
    Expr* condEIf = expr();
    match(GROUPEND);
    Stmnt* stEIf = stmnt();
    Stmnt* e = Else();
    elseSt = new QFresh(condEIf, stEIf, e);
  }
  else if(curToken->tag == ELSE)
  {
    move();
    Stmnt* st = stmnt();
    elseSt = new Expired(st);
  }

  return elseSt;
}

/******EBNF******
<expr> -> <mult> | id | <factor> | <sum>
<mult> -> <expr> (* | / ) (<expr> | (<sum>))
<sum> -> <expr> (+ | -) ((<expr>))
*/
Expr* Analyzer::expr(){
  Expr* e = boolean();
  return e;
}

//<bool> -> (bacon | sausage | <equality> | <logicBool>)  [ || <bool>]
Expr* Analyzer::boolean(){
  Expr* e = logicBool();
  while(curToken->tag == OR)
  {
    Token* saveTok = curToken;
    move();
    return new OrLogicExpr(saveTok, e, logicBool());
  }
  return e;
}

//<logicBool> -> <bool> && <bool>
Expr* Analyzer::logicBool(){
  Expr* e = equality();
  while(curToken->tag == AND)
  {
    Token* saveTok = curToken;
    move();
    return new AndLogicExpr(saveTok, e, equality());
  }
  return e;
}

//<equality> -> <bool> <equalityOp> <bool>
Expr* Analyzer::equality(){
  Expr* e = equalityOp();
  if(curToken->tag == EQ || curToken->tag == NEQ){
    Token* saveToken = curToken;
    move();
    return new LogicRelExpr(saveToken, e, equalityOp());
  }
  return e;
}

//<equalityOp> -> <==> | <=!=> | > | < | >= | <=
Expr* Analyzer::equalityOp(){
  Expr* e = sum();
  if(curToken->tag == LE ||
    curToken->tag == GE ||
    curToken->tag == LESSTHAN ||
    curToken->tag == GREATERTHAN)
    {
      Token* saveToken = curToken;
      move();
      return new LogicRelExpr(saveToken, e, sum());
    }
    return e;
}

Expr* Analyzer::sum(){
  Expr* e = mult();
  if(curToken->tag == PLUS || curToken->tag == MINUS)
  {
    Token* saveToken = curToken;
    move();
    return new Arithmetic(saveToken, e, mult());
  }
  return e;
}

Expr* Analyzer::mult()
{
  Expr* e = mod();
  if(curToken->tag == MULT || curToken->tag == DIV)
  {
    Token* saveToken = curToken;
    move();
    return new Arithmetic(saveToken, e, mod());
  }
  return e;
}

Expr* Analyzer::mod()
{
  Expr* e = unary();
  if(curToken->tag == MOD)
  {
    Token* saveToken = curToken;
    move();
    return new Arithmetic(saveToken, e, unary());
  }
  return e;
}

Expr* Analyzer::unary()
{
  if(curToken->tag == MINUS) {
      move();
      return new Unary(Word::Minus, unary());
  }
  else if(curToken->tag == '!') {
     Token* tok = curToken;
     move();
     return new Not(tok, unary());
  }
  else return factor();
}

Expr* Analyzer::factor()
{
  Expr* n = NULL;
  switch(curToken->tag){

    default:
      throwError("SYNTAX ERROR");
      return n;

    case GROUPSTART:
      move();
      n = expr();
      match(GROUPEND);
      return n;

    case NUM:
      n = new Const(curToken, Type::integer);
      move();
      return n;

    case FLOATING:
      n = new Const(curToken, Type::floating);
      move();
      return n;

    case TRU:
      if (Const::trueConst->type == NULL)
      {
        Const::trueConst->type = Type::boolean;
      }
      n = Const::trueConst;
      move();
      return n;

    case FALS:
      if (Const::trueConst->type == NULL)
      {
        Const::trueConst->type = Type::boolean;
      }
      n = Const::falseConst;
      move();
      return n;

    case '\'':
      move();
      n = new Const(curToken, Type::ch);
      move();
      match('\'');
      return n;

    case ID:
      n = top->getIdForToken(curToken);

      //Declared?
      if(n == NULL)
      {
        std::stringstream ss;
        ss << "Variable " << curToken->getName() << " undeclared\n";
        throwError(ss.str());
      }
      match(ID);

      //Check if this is a function call identifier
      if(curToken->tag == GROUPSTART)
      {
        match(GROUPSTART);
        std::vector<Expr*> params;
        if(curToken->tag != GROUPEND)
        {
          //Build params for call
          do{
            if(curToken->tag == PARAMSEP) move();
            params.push_back(expr());
          }while(curToken->tag == PARAMSEP);
        }

        match(GROUPEND);
        Id* func = top->getIdForToken(n->op);
        if(func == NULL)
        {
          throwError("Function Never declared!");
        }
        FunctionCall* fc = new FunctionCall(n->op, n->type, params, func);

        return fc;
      }
      if(curToken->tag == '[')
      {
        ArrayAccess* aa = offset(top->getIdForToken(n->op));
        n = aa;
      }
      return n;

    case IN:
    {
      //stdin line
      match(IN);
      match(GROUPSTART);
      if(!(curToken->tag == NUM || curToken->tag == FLOATING))
      {
        throwError("Expected num of chars to read!");
      }
      Number* num = (Number*)curToken;
      n = new OrderIn(num->value);
      match(NUM);
      match(GROUPEND);
      return n;
    }

    case STLIT:
      //a string literal token
      Word* str = (Word*)curToken;
      n = new Const(curToken, new Array(Type::ch, str->lexeme.length()));
      move();
      return n;
  }
}
void Analyzer::declarations()
{
  while(curToken->tag == BASICTYPE)
  {
    declaration();
    match(LINEEND);
  }
}
void Analyzer::declaration(){
  //Parse the type
  Type* t = type();
  match(ASSIGNTYPE); //@

  //Parse the ID
  Token* idTok = curToken;
  if(curToken->tag != ID)
  {
    throwError("Variable name required for assignment\n");
  }
  match(ID);

  //Add it to the symbol table
  top->addSymbol(idTok, new Id(idTok, t, used));
  used = used + t->width;

  #ifdef DEBUG
  std::cout << "Added: " << idTok->getString() << std::endl;
  #endif
}

Type* Analyzer::type(){
  Type* t = (Type*)curToken;
  if(curToken->tag != BASICTYPE)
  {
    throwError("Missing required type\n");
  }
  match(BASICTYPE);
  if(curToken->tag == '[')
  {
    move();
    Number* n = (Number*)curToken;
    if(curToken->tag == ']')
    {
      throwError("Must Specify array size\n");
    }
    match(NUM);

    //Create array type item
    Array* a = new Array(t, n->value);
    match(']');
    return a;
  }
  else return t;
}

ArrayAccess* Analyzer::offset(Id* id)
{
  #ifdef DEBUG
  std::cout << "ACCESSING ARRAY" << std::endl;
  #endif

  Expr* elemExpr;
  match('[');
  elemExpr = expr();
  match(']');

  Type* type = id->type;
  Expr* widthE = new Const(type->width);
  Expr* arrayElem = new Arithmetic(Word::Mult, elemExpr, widthE);
  ArrayAccess* aa = new ArrayAccess(id, arrayElem, id->type);
  return aa;
}
