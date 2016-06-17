#include "logicexpr.h"

void LogicExpr::printNode()
{
  printTabs();
  std::cout << "========LogicExpr Node========" << std::endl;
  Expr::printNode();
  tabs++;
  if(op1 != NULL) op1->printNode();
  if(op2 != NULL) op2->printNode();
  tabs--;
  printEndNode();
}
