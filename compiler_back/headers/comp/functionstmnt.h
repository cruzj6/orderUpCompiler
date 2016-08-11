#pragma once
#include "comp/stmnt.h"
#include "comp/expr.h"

class FunctionStmnt : public Stmnt{
public:
  FunctionStmnt(Expr* call);
  ~FunctionStmnt();
  void printNode();
  void gen(int b, int a);
private:
  Expr* funcCall;
};
