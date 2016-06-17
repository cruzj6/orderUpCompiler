#pragma once
#include "expr.h"

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
