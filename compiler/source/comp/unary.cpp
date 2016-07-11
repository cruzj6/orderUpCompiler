#include "comp/unary.h"
void Unary::printNode()
{
  printTabs();
  std::cout << "========Unary Node========" << std::endl;
  Op::printNode();
  tabs++;
  if(expr != NULL) expr->printNode();
    tabs--;
    printEndNode();

}
