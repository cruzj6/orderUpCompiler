#include "comp/op.h"
void Op::printNode()
{
  printTabs();
  std::cout << "========Op Node========" << std::endl;
  Expr::printNode();
  printEndNode();
}
