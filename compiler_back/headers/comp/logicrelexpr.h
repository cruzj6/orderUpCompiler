#pragma once
#include "comp/logicexpr.h"
#include "comp/error.h"

// <==> or <=!=>
class LogicRelExpr : public LogicExpr{
public:
  LogicRelExpr(Token* o, Expr* e1, Expr* e2);
  void printNode();
  void jumping(int t, int f);
};
