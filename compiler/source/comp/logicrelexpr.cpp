#include "comp/logicrelexpr.h"
void LogicRelExpr::printNode()
{
  printTabs();
  std::cout << "========LogicRelExpr Node========" << std::endl;
  LogicExpr::printNode();
  printEndNode();
}
