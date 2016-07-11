#include "comp/arrayaccess.h"
void ArrayAccess::printNode()
{
  printTabs();
  std::cout << "========ArrayAccess Node========" << std::endl;
  Op::printNode();
  tabs++;
  if(array != NULL) array->printNode();
  if(index != NULL) index->printNode();
  tabs--;
  printEndNode();
}
