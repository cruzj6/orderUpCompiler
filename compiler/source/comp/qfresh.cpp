#include "comp/qfresh.h"
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
