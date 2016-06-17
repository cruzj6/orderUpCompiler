#include "functionid.h"
void FunctionId::printNode()
{
  printTabs();
  std::cout << "========FunctionId Node========" << std::endl;
  std::cout << "ReturnType: " << retType->getString() << std::endl;
  Id::printNode();
  printEndNode();
}
