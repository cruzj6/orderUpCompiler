#pragma once
#include "comp/expr.h"

class LogicExpr : public Expr{
public:
  LogicExpr(Token* o, Expr* e1, Expr* e2);
  ~LogicExpr();
  Expr* gen();
  void printNode();
  std::string toString();
  Expr* op1;
  Expr* op2;
};
