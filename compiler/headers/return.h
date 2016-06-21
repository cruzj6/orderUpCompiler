#pragma once
#include "stmnt.h"
#include "expr.h"

class Return : public Stmnt{
public:
  Return(Expr* retExpr)
  {
    ret = retExpr;
  }
  ~Return()
  {
    delete ret;
  }
  Expr* ret;
  void printNode();
};
