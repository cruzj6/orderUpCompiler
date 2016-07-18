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
  /*int label1 = newLabel();      // stmt1 label
  int label2 = newLabel();      // stmt2 label
  expr.jumping(0, label2);       // true : fall thru to stmt1

  // label & code for true
  emitLabel(label1);
  stmt1->gen(label1, a);

  std::stringstream ss;
  ss << "goto L" << a;
  emit(ss.str());	    // skip false

  // label & code for false
  emitLabel(label2);
  stmt2->gen(label2,a);*/
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
