#include "function.h"
void Function::printNode()
{
  printTabs();
  std::cout << "========Function Node========" << std::endl;
  Stmnt::printNode();
  tabs++;
  if(retType != NULL) std::cout << retType->getString() << std::endl;
  std::vector<Id*>::iterator it;
  for(it = params.begin(); it != params.end(); it++)
  {
    (*it)->printNode();
  }
  if(funcBlock != NULL) funcBlock->printNode();
  tabs--;
  printEndNode();
}
