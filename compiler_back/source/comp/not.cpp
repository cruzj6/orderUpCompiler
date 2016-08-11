#include "comp/not.h"
void Not::printNode()
{
  printTabs();
  std::cerr << "========Not Node========" << std::endl;
  LogicExpr::printNode();
  printEndNode();
}

void Not::jumping(int t, int f)
{
  //Just reverse
  return op2->jumping(f, t);
}

std::string Not::toString()
{
  return op->toString() + " " + op2->toString();
}
