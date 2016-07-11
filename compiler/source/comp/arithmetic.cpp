#include "comp/arithmetic.h"
#include "comp/error.h"


Arithmetic::Arithmetic(Token* o, Expr* e1, Expr* e2) : Expr(o, checkType(e1, e2)){
  op1 = e1;
  op2 = e2;
}
Arithmetic::~Arithmetic()
{
  delete op1;
  delete op2;
}

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
  std::cout << e1->type->getString() << e2->type->getString() << std::endl;
  if(!Type::isNumericType(e1->type) || !Type::isNumericType(e2->type))
  {
    Error* e = new Error();
    e->msg = "Expected numeric expression";
    throw *e;
  }
  else if(e1->type == Type::floating || e2->type == Type::floating)
  {
    return Type::floating;
  }
  return Type::integer;
}
