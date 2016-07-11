#include "comp/functionstmnt.h"
void FunctionStmnt::printNode()
{
  printTabs();
  std::cout << "========FunctionStmnt Node========" << std::endl;
  Stmnt::printNode();
  tabs++;
  if(funcCall != NULL) funcCall->printNode();
  tabs--;
  printEndNode();
}
