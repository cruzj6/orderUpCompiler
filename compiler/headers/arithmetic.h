#pragma once
#include "expr.h"

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
