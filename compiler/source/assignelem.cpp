#include "assignelem.h"
void AssignElem::printNode()
{
  printTabs();
  std::cout << "========AssignElem Node========" << std::endl;
  Stmnt::printNode();
  if(index != NULL) index->printNode();
  if(expr != NULL) expr->printNode();
  if(array != NULL) array->printNode();
  printEndNode();
}
