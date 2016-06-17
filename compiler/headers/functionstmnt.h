#pragma once
#include "stmnt.h"
#include "expr.h"

class FunctionStmnt : public Stmnt{
public:
  FunctionStmnt(Expr* call)
  {
    funcCall = call;
  }
  void printNode();
private:
  Expr* funcCall;
};
