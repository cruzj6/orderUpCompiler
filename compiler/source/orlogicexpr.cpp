#include "orlogicexpr.h"

void OrLogicExpr::printNode()
{
  printTabs();
  std::cout << "========OrLogicExpr Node========" << std::endl;
  LogicExpr::printNode();
  printEndNode();
}
