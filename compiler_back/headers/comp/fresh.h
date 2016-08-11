#pragma once
#include "comp/expr.h"
#include "comp/stmnt.h"

class Fresh : public Stmnt{
public:
  Fresh(Expr* cond, Stmnt* st,  Stmnt* el);
  void printNode();
  void gen(int b, int a);
  ~Fresh();
private:
  Expr* booleanExpr; //Must be boolean/baconOrSausage Type
  Stmnt* stmnt; //My Stmnt
  Stmnt* elseStmnt; //Else or else if
};
