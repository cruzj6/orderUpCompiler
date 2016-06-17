#pragma once
#include "stmnt.h"
#include "expr.h"

class Return : public Stmnt{
public:
  Return(Expr* retExpr)
  {
    ret = retExpr;
  }
  Expr* ret;
  void printNode();
};
