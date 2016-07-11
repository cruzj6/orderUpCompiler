#include "comp/orderin.h"
void OrderIn::printNode()
{
  printTabs();
  std::cout << "========OrderIn Node========" << std::endl;
  Expr::printNode();
  printEndNode();
}
