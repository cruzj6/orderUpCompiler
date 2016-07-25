#pragma once
#include "comp/stmnt.h"
#include "comp/expr.h"
class QFresh : public Stmnt{
public:
  QFresh(Expr* cond, Stmnt* st1, Stmnt* st2);
  ~QFresh();
  void printNode();
  void gen(int b, int a);
private:
  Expr* booleanExpr; //Must be boolean/baconOrSausage Type
  Stmnt* stmnt; //my Stmnt
  Stmnt* chainStmnt; //Next else if or else
};
