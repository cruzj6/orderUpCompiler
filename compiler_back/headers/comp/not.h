#pragma once
#include "comp/logicexpr.h"

class Not : public LogicExpr{
public:
  Not(Token* o, Expr* e) : LogicExpr(o, e, e){}
  void printNode();
  void jumping(int t, int f);
  std::string toString();
};
