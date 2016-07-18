#include "comp/unary.h"

Unary::Unary(Token* o, Expr* e) : Op(o, e->type)
{
  expr = e;
}

Unary::~Unary()
{
  delete expr;
}

std::string Unary::toString()
{
  return op->toString() + " " + expr->toString();
}

Expr* Unary::gen()
{
  //Reduce to address
  return new Unary(op, expr->reduce());
}

void Unary::printNode()
{
  printTabs();
  std::cerr << "========Unary Node========" << std::endl;
  Op::printNode();
  tabs++;
  if(expr != NULL) expr->printNode();
    tabs--;
    printEndNode();

}
