#include "comp/andlogicexpr.h"
void AndLogicExpr::printNode()
{
  printTabs();
  std::cout << "========AndLogicExpr Node========" << std::endl;
  LogicExpr::printNode();
  printEndNode();
}
