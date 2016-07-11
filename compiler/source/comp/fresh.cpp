#include "comp/fresh.h"

Fresh::Fresh(Expr* cond, Stmnt* st,  Stmnt* el)
{
  booleanExpr = cond;
  stmnt = st;
  elseStmnt = el;
  if(cond->type != Type::boolean)
  {
    Error* e  = new Error();
    e->msg = "Expected Boolean(baconOrSausage) value for fresh(if) statement";
    throw *e;
  }
}

Fresh::~Fresh()
{
  delete booleanExpr;
  delete stmnt;
}

void Fresh::printNode()
{
  printTabs();
  std::cout << "========Fresh Node========" << std::endl;
  Stmnt::printNode();
  tabs++;
  if(booleanExpr != NULL) booleanExpr->printNode();
  if(stmnt != NULL) stmnt->printNode();
  if(elseStmnt != NULL) elseStmnt->printNode();
  tabs--;
  printEndNode();
}
