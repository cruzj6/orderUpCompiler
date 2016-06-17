#include "assign.h"
void Assign::printNode()
{
  printTabs();
  std::cout << "========Assign Node========" << std::endl;
  Stmnt::printNode();
  tabs++;
  if(expr != NULL) expr->printNode();
  if(id != NULL) {id->printNode();}
  tabs--;
  printEndNode();
}
