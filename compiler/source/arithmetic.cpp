#include "arithmetic.h"
void Arithmetic::printNode()
{
  printTabs();
  std::cout << "========Arithmetic Node========" << std::endl;
  Expr::printNode();
  tabs++;
  if(op1 != NULL) {
    op1->printNode();
  }
  if(op2 != NULL) {
    op2->printNode();
  }
  tabs--;
  printEndNode();
}

Type* Arithmetic::checkType(Expr* e1, Expr* e2)
{
  if(e1->type == Type::floating || e2->type == Type::floating)
  {
    return Type::floating;
  }
  return Type::integer;
}
