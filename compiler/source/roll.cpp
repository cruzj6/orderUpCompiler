#include "roll.h"
void Roll::printNode()
{
  printTabs();
  std::cout << "========Roll Node========" << std::endl;
  Stmnt::printNode();
  tabs++;
  if(counter != NULL) counter->printNode();
  if(startNum != NULL) startNum->printNode();
  if(endNum != NULL) endNum->printNode();
  if(stepBy != NULL) stepBy->printNode();
  if(stmnt != NULL) stmnt->printNode();
  tabs--;
  printEndNode();
}
