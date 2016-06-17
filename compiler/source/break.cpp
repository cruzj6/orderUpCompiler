#include "break.h"
void Break::printNode()
{
  printTabs();
  std::cout << "========Break Node========" << std::endl;
  Stmnt::printNode();
}
