#include "comp/serveout.h"
void ServeOut::printNode()
{
  printTabs();
  std::cout << "========ServeOut Node========" << std::endl;
  Stmnt::printNode();
  tabs++;
  if(outExpr != NULL) outExpr->printNode();
  tabs--;
  printEndNode();
}
