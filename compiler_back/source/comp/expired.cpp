#include "comp/expired.h"

Expired::Expired(Stmnt* st)
{
  blockStmnt = st;
}

Expired::~Expired(){
  delete blockStmnt;
}

void Expired::gen(int b, int a)
{
  int label1 = newLabel();      // stmt1 label

  // label & code for the statement
  emitLabel(label1);
  if (blockStmnt != NULL) blockStmnt->gen(label1, a);
}

void Expired::printNode()
{
  printTabs();
  std::cerr << "========Expired Node========" << std::endl;
  Stmnt::printNode();
  tabs++;
  if(blockStmnt != NULL) blockStmnt->printNode();
  tabs--;
  printEndNode();
}
