#include "comp/functionstmnt.h"
void FunctionStmnt::printNode()
{
  printTabs();
  std::cerr << "========FunctionStmnt Node========" << std::endl;
  Stmnt::printNode();
  tabs++;
  if(funcCall != NULL) funcCall->printNode();
  tabs--;
  printEndNode();
}
