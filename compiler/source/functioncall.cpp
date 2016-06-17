#include "functioncall.h"
void FunctionCall::printNode()
{
  printTabs();
  std::cout << "========FunctionCall Node========" << std::endl;
  Expr::printNode();
  tabs++;
  std::vector<Expr*>::iterator it;
  for(it = params.begin(); it != params.end(); it++)
  {
    (*it)->printNode();
  }
  tabs--;
  printEndNode();
}
