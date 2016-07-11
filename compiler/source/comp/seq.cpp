#include "comp/seq.h"
void Seq::printNode()
{
  printTabs();
  std::cout << "========Seq Node========" << std::endl;
  Stmnt::printNode();
  tabs++;
  if(st1 != NULL) st1->printNode();
  if(st2 != NULL) st2->printNode();
  tabs--;
  printEndNode();
}
