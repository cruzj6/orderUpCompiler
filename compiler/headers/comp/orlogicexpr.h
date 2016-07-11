#pragma once
#include "comp/logicexpr.h"

class OrLogicExpr : public LogicExpr{
public:
  OrLogicExpr(Token* o,  Expr* e1, Expr* e2) : LogicExpr(o, e1, e2){}
  void printNode();
};
