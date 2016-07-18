#include "comp/break.h"
void Break::printNode()
{
  printTabs();
  std::cerr << "========Break Node========" << std::endl;
  Stmnt::printNode();
}
