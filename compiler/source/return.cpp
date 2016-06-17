#include "return.h"
void Return::printNode()
{
  printTabs();
  std::cout << "========Return Node========" << std::endl;
  Stmnt::printNode();
  tabs++;
  if(ret != NULL) ret->printNode();
  tabs--;
  printEndNode();
}
