#pragma once
#include "logicexpr.h"

class AndLogicExpr : public LogicExpr{
public:
  AndLogicExpr(Token* o,  Expr* e1, Expr* e2) : LogicExpr(o, e1, e2){}
  void printNode();
};
