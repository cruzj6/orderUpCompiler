#pragma once
#include "comp/id.h"
#include "symbols/functionType.h"
#include "comp/stmnt.h"
#include "comp/expr.h"

class Return : public Stmnt{
public:
  Return(Expr* retExpr);
  ~Return();
  Expr* ret;
  void printNode();
  static Id* curFuncBlock;
  void gen(int b, int a);
};
