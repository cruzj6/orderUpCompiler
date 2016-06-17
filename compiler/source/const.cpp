#include "const.h"
Const* Const::trueConst  = new Const(Word::BTrue,  Type::boolean);
Const* Const::falseConst = new Const(Word::BFalse, Type::boolean);

void Const::printNode()
{
  printTabs();
  std::cout << "========Const Node========" << std::endl;
  Expr::printNode();
  printEndNode();
}
