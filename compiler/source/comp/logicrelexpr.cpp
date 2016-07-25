#include "comp/logicrelexpr.h"

LogicRelExpr::LogicRelExpr(Token* o, Expr* e1, Expr* e2) : LogicExpr(o, e1, e2)
{}

void LogicRelExpr::printNode()
{
  printTabs();
  std::cerr << "========LogicRelExpr Node========" << std::endl;
  LogicExpr::printNode();
  printEndNode();
}

void LogicRelExpr::jumping(int t, int f)
{
  Expr* a = op1->reduce();
  Expr* b = op2->reduce();
  std::string test = a->toString() + " " + op->toString() + " " +
    (b->toString() == "" ? Word::BTrue->toString() : b->toString());
  emitJumps(test, t, f);
}
