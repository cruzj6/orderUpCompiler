#pragma once
#include "comp/stmnt.h"
#include "comp/expr.h"

class FunctionStmnt : public Stmnt{
public:
  FunctionStmnt(Expr* call)
  {
    funcCall = call;
  }
  ~FunctionStmnt(){
    delete funcCall;
  }
  void printNode();
private:
  Expr* funcCall;
};
