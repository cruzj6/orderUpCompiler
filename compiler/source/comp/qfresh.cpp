#include "comp/qfresh.h"

QFresh::QFresh(Expr* cond, Stmnt* st1, Stmnt* st2)
{
  booleanExpr = cond;
  stmnt = st1;
  chainStmnt = st2;
}

QFresh::~QFresh()
{
  delete booleanExpr;
  delete stmnt;
}

void QFresh::gen(int b, int a)
{
  if(chainStmnt != NULL)
  {
    std::stringstream ss;
    int label = newLabel();
    int labelElse = newLabel();
    booleanExpr->jumping(0, labelElse);//True fall to stmnt, else go to label else
    emitLabel(label);
    if(stmnt != NULL) stmnt->gen(label, a);

    //Skip the else we got a true
    ss << "goto L" << a;
    emit(ss.str());

    //Emit label for else stmnt
    emitLabel(labelElse);
    chainStmnt->gen(label, a);
  }
  else {
    int label = newLabel();
    booleanExpr->jumping(0, a);//True fall to stmnt, else go to label a
    emitLabel(label);
    if (stmnt != NULL)stmnt->gen(label, a);
  }
}

void QFresh::printNode()
{
  printTabs();
  std::cerr << "========QFresh Node========" << std::endl;
  Stmnt::printNode();
  tabs++;
  if(booleanExpr != NULL) {booleanExpr->printNode();}
  if(stmnt != NULL) stmnt->printNode();
  if(chainStmnt != NULL) chainStmnt->printNode();
  tabs--;
  printEndNode();
}
