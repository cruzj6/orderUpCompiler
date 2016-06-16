#include "analyzer.h"
#include "stmnt.h"
#include "env.h"
#include "type.h"
#include "id.h"
#include "error.h"
#include <sstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>

Stmnt* Stmnt::Enclosing = NULL;
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

  try{
    Stmnt* s = functions(); //Get the syntax/parse tree
    s->printNode();
  }
  catch(Error e)
  {
    //Throw errors tacking on line number
    throwError(e.ShowReason());
  }
}

void Analyzer::match(int toMatch)
{
  Token* saveToken = curToken;
  std::cout << "=============Match===========" << std::endl;
  if(curToken->tag == -1)
  {
    std::stringstream ss;
    ss << "Unknown token: " << curToken->unknownToken << "\n";
    std::cout << saveToken->getString() << std::endl;
    throwError(ss.str());
  }
  else if(curToken->tag == toMatch)
  {
    std::cout << "Good" << std::endl;
    std::cout << saveToken->getString() << std::endl;
    move();
  }
  else
  {
    std::cout << saveToken->getString() << std::endl;
    std::stringstream ss;
    ss << "Expected token tag: " << toMatch << "\n";

    throwError(ss.str());
  }

  std::cout << "=============================" << std::endl;
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
  //Build globals, these can come before any
  //function so build each time
  declarations();
  Stmnt* node;

  if(curToken->tag == ENDOFFILE)
  {
    return NULL;
  }
  //Create new sequence for each statement, passing it function as statement
  node = new Seq(function(), functions());
  return node;
}

Stmnt* Analyzer::function(){
  //A function should now start
  match(FUNC); //breakfastOrder
  Token* funcTok = curToken;
  match(ID); //func name

  //Add the func to symbol table, its of type function
  top->addSymbol(funcTok, new Id(funcTok, Type::function, used));
  used = used + Type::function->width;

  //Function scope symbol table to top
  Env* saveTop = top;
  top = new Env(top);
  match(GROUPSTART); //open paren

  std::vector<Id*> params;

  //If no close paren yet, this must be declaration for param
  //Allocate space for all of the params
  if(curToken->tag != GROUPEND)
  {
    //Expect declaration param
    do{
      move();

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
  else{
    match(GROUPEND);
  }
  Type* t = NULL;
  if(curToken->tag == RETTYPE)
  {
    //Func return type store
    match(RETTYPE);
    t = dynamic_cast<Type*>(curToken);
    match(BASICTYPE);
  }

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

  //Delete the sub symbol table when we exit
  //TODO: delete tempTop;
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
      Word* w = dynamic_cast<Word*>(curToken);
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
     Expr* cond = expr();
     match(GROUPEND);
     Stmnt* st = stmnt();
     std::cout << "THE TOKEN: " << curToken->getString() << std::endl;
     Stmnt* elseChain = Else();
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
     match(RETSTMNT);
     Expr* retStmnt = expr();
     match(LINEEND);
     return new Return(retStmnt);
   }
   else if(curToken->tag == OUT)
   {
     match(OUT);
     match(GROUPSTART);
     Expr* e = expr();
     match(GROUPEND);
     match(LINEEND);
     return new ServeOut(e);
   }
   else //Assume assignment statement
   {
     Id* id = top->getIdForToken(curToken);
     if(id == NULL)
     {
       std::stringstream ss;
       ss << "Identifier never declared: " << curToken->getString() << "\n";
       throwError(ss.str());
     }
     match(ID);
     if(curToken->tag == ASSIGN){

       //Should be an assignment
       match(ASSIGN);
       Expr* val = expr();
       match(LINEEND);
       Assign* a = new Assign(id, val);
       return a;
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
  Stmnt* elseSt;
  if(curToken->tag == ELSEIF){
    match(GROUPSTART);
    Expr* condEIf = expr();
    match(GROUPEND);
    Stmnt* stEIf = stmnt();
    elseSt = new QFresh(condEIf, stEIf, Else());
  }
  else if(curToken->tag == ELSE)
  {
    move();
    Stmnt* st = stmnt();
    elseSt = new Expired(st);
  }

  return elseSt;
}
Expr* Analyzer::expr(){
  Expr* e = boolean();
  return e;
}

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

Expr* Analyzer::equality(){
  Expr* e = equalityOp();
  if(curToken->tag == EQ || curToken->tag == NEQ){
    Token* saveToken = curToken;
    move();
    return new LogicRelExpr(saveToken, e, equalityOp());
  }
  return e;
}

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
  Expr* e = unary();
  if(curToken->tag == MULT || curToken->tag == DIV)
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
      std::cout << curToken->getString() << std::endl;
      move();
      return n;

    case FLOATING:
      n = new Const(curToken, Type::floating);
      move();
      return n;

    case TRUE:
      n = Const::trueConst;
      move();
      return n;

    case FALSE:
      n = Const::falseConst;
      move();
      return n;

    case ID:
      n = top->getIdForToken(curToken);
      if(n == NULL)
      {
        std::stringstream ss;
        ss << curToken->getString() << "undeclared\n";
        throwError(ss.str());
      }
      move();
      return n;

    case IN:
      n = new OrderIn();
      move();
      return n;

    case STLIT:
      Word* str = dynamic_cast<Word*>(curToken);
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
  match(ID);

  //Add it to the symbol table
  top->addSymbol(idTok, new Id(idTok, t, used));
  std::cout << "Added: " << idTok->getString() << std::endl;
  used = used + t->width;
}

Type* Analyzer::type(){
  Type* t = dynamic_cast<Type*>(curToken);
  match(BASICTYPE);

  if(curToken->tag == '[')
  {
    move();
    Number* n = dynamic_cast<Number*>(curToken);
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
  Expr* elemExpr;
  std::cout << "ACCESSING ARRAY" << std::endl;
  match('[');
  elemExpr = expr();
  match(']');

  Type* type = id->type;
  Expr* widthE = new Const(type->width);
  Expr* arrayElem = new Arithmetic(Word::Mult, elemExpr, widthE);

  ArrayAccess* aa = new ArrayAccess(id, arrayElem, id->type);
  return aa;
}
