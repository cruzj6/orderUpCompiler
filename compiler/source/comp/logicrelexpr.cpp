#include "comp/logicrelexpr.h"
void LogicRelExpr::printNode()
{
  printTabs();
  std::cerr << "========LogicRelExpr Node========" << std::endl;
  LogicExpr::printNode();
  printEndNode();
}

void LogicRelExpr::jumping(int t, int f)
{
  // Reduce expression 1 to an address (temporary, constant or identifier)
  // Example:   With a + b < d  then a + b ==> t1
  Expr* a = op1->reduce();

  // Reduce expression 2 to an address (temporary, constant or identifier)
  Expr* b = op2->reduce();

  // Code for the relational expression with op1 and op2 reducded to
  // addresses.
  std::string test = a->toString() + " " + op->toString() + " " + b->toString();

  // Generate code to perform jumps based on the test (see class Expr)
  emitJumps(test, t, f);
}
