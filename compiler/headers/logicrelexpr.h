#pragma once
#include "logicexpr.h"

// <==> or <=!=>
class LogicRelExpr : public LogicExpr{
public:
  LogicRelExpr(Token* o, Expr* e1, Expr* e2) : LogicExpr(o, e1, e2){}
  void printNode();
};