#include "not.h"
void Not::printNode()
{
  printTabs();
  std::cout << "========Not Node========" << std::endl;
  LogicExpr::printNode();
  printEndNode();
}
