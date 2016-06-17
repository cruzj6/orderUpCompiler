#pragma once
#include "expr.h"
#include "stmnt.h"

class Fresh : public Stmnt{
public:
  Fresh(Expr* cond, Stmnt* st,  Stmnt* el)
  {
    booleanExpr = cond;
    stmnt = st;
    elseStmnt = el;
  }
  void printNode();
  ~Fresh()
  {
    delete booleanExpr;
    delete stmnt;
  }
private:
  Expr* booleanExpr; //Must be boolean/baconOrSausage Type
  Stmnt* stmnt; //My Stmnt
  Stmnt* elseStmnt; //Else or else if
};
