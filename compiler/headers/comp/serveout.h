#pragma once
#include "comp/stmnt.h"
#include "comp/expr.h"
class ServeOut : public Stmnt{
public:
  ServeOut(Expr* out);
  ~ServeOut();
  void printNode();
  void gen(int b, int a);
private:
  Expr* outExpr;
};
