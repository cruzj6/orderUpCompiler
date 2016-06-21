#pragma once
#include "stmnt.h"
#include "expr.h"
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
