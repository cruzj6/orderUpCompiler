#pragma once
#include "comp/stmnt.h"
#include "comp/expr.h"
class ServeOut : public Stmnt{
public:
  ServeOut(Expr* out)
  {
    outExpr = out;
  }
  ~ServeOut()
  {
    delete outExpr;
  }
  void printNode();
private:
  Expr* outExpr;
};
