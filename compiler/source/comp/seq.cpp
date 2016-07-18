#include "comp/seq.h"

Seq::Seq(Stmnt* s1, Stmnt* s2)
{
  st1 = s1;
  st2 = s2;
}

Seq::~Seq()
{
  delete st1;
  delete st2;
}

void Seq::gen(int b, int a)
{
  // Only have statement 2
 if (st1 == NULL)
     st2->gen(b, a);
 // Only have statement 1
 else if (st2 == NULL)
     st1->gen(b, a);
 else
 {
    int label = newLabel(); // Label between stmt1 and stmt2
    st1->gen(b,label);     // code for stmt1
    emitLabel(label);       // Print label
    st2->gen(label,a);     // code for stmt2
 }
}

void Seq::printNode()
{
  printTabs();
  std::cerr << "========Seq Node========" << std::endl;
  Stmnt::printNode();
  tabs++;
  if(st1 != NULL) st1->printNode();
  if(st2 != NULL) st2->printNode();
  tabs--;
  printEndNode();
}
