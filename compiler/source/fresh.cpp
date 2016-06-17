#include "fresh.h"
void Fresh::printNode()
{
  printTabs();
  std::cout << "========Fresh Node========" << std::endl;
  Stmnt::printNode();
  tabs++;
  if(booleanExpr != NULL) booleanExpr->printNode();
  if(stmnt != NULL) stmnt->printNode();
  if(elseStmnt != NULL) elseStmnt->printNode();
  tabs--;
  printEndNode();
}
