#include "comp/andlogicexpr.h"
void AndLogicExpr::printNode()
{
  printTabs();
  std::cerr << "========AndLogicExpr Node========" << std::endl;
  LogicExpr::printNode();
  printEndNode();
}

void AndLogicExpr::jumping(int t, int f)
{
  int label = (f != 0) ? f : newLabel();

  // Generate code for op1
  // if op1 is true, still have to test op2 (fall through)
  op1->jumping(0, label);

  // Generate code for op2
  // if op2 is true, expr is true
  // if op2 is false expr is false
  op2->jumping(t, f);

  if(f == 0)
    emitLabel(label);
}
