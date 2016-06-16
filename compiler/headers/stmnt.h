#pragma once
#include "node.h"
#include "error.h"
#include "Number.h"
#include <stdio.h>
#include <vector>
//Expression containers
class Expr : public Node{
public:
  Expr(Token* o, Type* t)
  {
    op = o;
    type = t;
  }
  Token* op;
  Type* type; //What this statement "returns"
  void printNode();
};

class Id : public Expr{
private:
  int offset;

public:
  Id(Token* o, Type* t, int off) : Expr(o, t)
  {
    offset = off;
  }

  Token* getToken();
  Type* getType();
  int getOffset();
  void printNode();
};

class OrderIn : public Expr{
public:
  OrderIn() : Expr(NULL, Type::ch)
  {

  }
  void printNode();
};

//Type must be wholeMilk or percentMilk
class Arithmetic : public Expr{
public:
  Arithmetic(Token* o, Expr* e1, Expr* e2) : Expr(o, checkType(e1, e2)){
    op1 = e1;
    op2 = e2;
  }
  Expr* op1;
  Expr* op2;
  void printNode();
private:
  Type* checkType(Expr* e1, Expr* e2);
};

class LogicExpr : public Expr{
public:
  LogicExpr(Token* o, Expr* e1, Expr* e2) : Expr(o, Type::boolean)
  {
    op1 = e1;
    op2 = e2;
  }
  void printNode();
  Expr* op1;
  Expr* op2;
};

class Not : public LogicExpr{
public:
  Not(Token* o, Expr* e) : LogicExpr(o, e, e){}
  void printNode();
};

class OrLogicExpr : public LogicExpr{
public:
  OrLogicExpr(Token* o,  Expr* e1, Expr* e2) : LogicExpr(o, e1, e2){}
  void printNode();
};

class AndLogicExpr : public LogicExpr{
public:
  AndLogicExpr(Token* o,  Expr* e1, Expr* e2) : LogicExpr(o, e1, e2){}
  void printNode();
};

// <==> or <=!=>
class LogicRelExpr : public LogicExpr{
public:
  LogicRelExpr(Token* o, Expr* e1, Expr* e2) : LogicExpr(o, e1, e2)
  {}
    void printNode();
};

//No Id just a inline num or strlit or whatever
class Temp : public Expr{
public:
  Word* tempToken;
};

class Const : public Expr{
public:
  Const(Token* o, Type* t) : Expr(o, t){}
  Const(int i) : Expr(new Number(i), Type::integer){}
  void printNode();
  static Const* trueConst;
  static Const* falseConst;
};

class Op : public Expr{
public:
  Op(Token* o, Type* t) : Expr(o, t){}
  void printNode();
};

class ArrayAccess : public Op{
public:
  Id* array;
  Expr* index;
  ArrayAccess(Id* i, Expr* e, Type* t) : Op(new Word("[]", INDEX), t)
  {
    array = i;
    index = e;
  }
  void printNode();
};


class Unary : public Op{
public:
  Expr* expr;
  Unary(Token* o, Expr* e) : Op(o, e->type)
  {
    expr = e;
  }
  void printNode();
};

//Statement Containers
class Stmnt : public Node{
public:
  static Stmnt* Enclosing;
  virtual ~Stmnt(){}
  void printNode();
};

class Return : public Stmnt{
public:
  Return(Expr* retExpr)
  {
    ret = retExpr;
  }
  Expr* ret;
  void printNode();
};

class Break : public Stmnt{
public:
  Break(){
    if(Stmnt::Enclosing == NULL)
    {
      Error* e = new Error();
      e->msg = "Break is not enclosed!";
      throw *e;
    }
  }
  void printNode();
};

class Seq : public Stmnt{
public:
  Stmnt* st1;
  Stmnt* st2;
  void printNode();
  Seq(Stmnt* s1, Stmnt* s2)
  {
    st1 = s1;
    st2 = s2;
  }
  ~Seq()
  {
    delete st1;
    delete st2;
  }
};

class ServeOut : public Stmnt{
public:
  ServeOut(Expr* out)
  {
    outExpr = out;
  }
  void printNode();
private:
  Expr* outExpr;
};


class OrderUp : public Stmnt{
public:
  Expr* expr; //Expression we are returning
  ~OrderUp()
  {
    delete expr;
  }
  void printNode();
};

class Assign : public Stmnt{
public:
  Assign(Id* i, Expr* val)
  {
    expr = val;
    id = i;
  }
  ~Assign(){
    delete expr;
    delete id;
  }
  void printNode();
private:
  Expr* expr; //Must be same type as Id
  Id* id;
};

class AssignElem : public Stmnt{
public:
  AssignElem(ArrayAccess* a, Expr* val)
  {
    array = a->array;
    expr = val;
    index = a->index;
  }
  void printNode();
private:
  Expr* index;
  Expr* expr; //Must be same type as Id
  Id* array;
};

class Roll : public Stmnt{
public:
  Roll()
  {
    counter = NULL;
    startNum = NULL;
    endNum = NULL;
    stepBy = NULL;
    stmnt = NULL;
  }
  void printNode();

  void init(Id* c, Expr* sNum, Expr* eNum, Expr* step, Stmnt* b)
  {
    counter = c;
    startNum = sNum;
    endNum = eNum;
    stepBy = step;
    stmnt = b;
  }
  ~Roll()
  {
    delete counter;
    delete startNum;
    delete endNum;
    delete stepBy;
    delete stmnt;
  }
private:
  Id* counter;
  Expr* startNum; //Must be wholeMilk/integer type
  Expr* endNum; //Must be  wholeMilk/integer type
  Expr* stepBy; //Must be  wholeMilk/integer type
  Stmnt* stmnt;
};

class Fresh : public Stmnt{
public:
  Fresh(Expr* cond, Stmnt* st,  Stmnt* el)
  {
    booleanExpr = cond;
    stmnt = st;
    elseStmnt = el;
  }
  void printNode();
  ~Fresh()
  {
    delete booleanExpr;
    delete stmnt;
  }
private:
  Expr* booleanExpr; //Must be boolean/baconOrSausage Type
  Stmnt* stmnt; //My Stmnt
  Stmnt* elseStmnt; //Else or else if
};

class QFresh : public Stmnt{
public:
  QFresh(Expr* cond, Stmnt* st1, Stmnt* st2)
  {
    stmnt = st1;
    chainStmnt = st2;
  }
  void printNode();
  ~QFresh()
  {
    delete booleanExpr;
    delete stmnt;
  }
private:
  Expr* booleanExpr; //Must be boolean/baconOrSausage Type
  Stmnt* stmnt; //my Stmnt
  Stmnt* chainStmnt; //Next else if or else
};

class Expired : public Stmnt{
public:
  Expired(Stmnt* st)
  {
    blockStmnt = st;
  }
  void printNode();
  ~Expired(){
    delete blockStmnt;
  }
private:
  Stmnt*  blockStmnt;
};

class Function : public Stmnt{
public:
  Function(std::vector<Id*> ps, Stmnt* blck, Type* rType){
    params = ps;
    funcBlock = blck;
    retType = rType;
  }
  void printNode();
  ~Function(){
    std::vector<Id*>::iterator it;
    for(it = params.begin(); it != params.end(); it++)
    {
      delete *it;
    }
    delete funcBlock;
  }
private:
  std::vector<Id*> params;
  Stmnt* funcBlock;
  Type* retType;
};
