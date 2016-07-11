#include "comp/expired.h"
void Expired::printNode()
{
  printTabs();
  std::cout << "========Expired Node========" << std::endl;
  Stmnt::printNode();
  tabs++;
  if(blockStmnt != NULL) blockStmnt->printNode();
  tabs--;
  printEndNode();
}
