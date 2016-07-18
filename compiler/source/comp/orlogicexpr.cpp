#include "comp/orlogicexpr.h"

void OrLogicExpr::printNode()
{
  printTabs();
  std::cerr << "========OrLogicExpr Node========" << std::endl;
  LogicExpr::printNode();
  printEndNode();
}

void OrLogicExpr::jumping(int t, int f)
{
  int label = (t != 0) ? t : newLabel();

  // op1 true, go to label, otherwise fall thru (have to test op2)
  op1->jumping(label, 0);

  //op2 true, goto true label, otherwise go to false label
  op2->jumping(t, f);

  if(t == 0)
      emitLabel(label);
}
