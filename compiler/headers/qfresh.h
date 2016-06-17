#pragma once
#include "stmnt.h"
#include "expr.h"
class QFresh : public Stmnt{
public:
  QFresh(Expr* cond, Stmnt* st1, Stmnt* st2)
  {
    booleanExpr = cond;
    stmnt = st1;
    chainStmnt = st2;
  }
  void printNode();
  ~QFresh()
  {
    delete booleanExpr;
    delete stmnt;
  }
private:
  Expr* booleanExpr; //Must be boolean/baconOrSausage Type
  Stmnt* stmnt; //my Stmnt
  Stmnt* chainStmnt; //Next else if or else
};
