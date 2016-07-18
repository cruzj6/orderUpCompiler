#include "comp/roll.h"
Roll::Roll()
{
  counter = NULL;
  startNum = NULL;
  endNum = NULL;
  stepBy = NULL;
  stmnt = NULL;
}

void Roll::init(Id* c, Expr* sNum, Expr* eNum, Expr* step, Stmnt* b)
{
  counter = c;
  startNum = sNum;
  endNum = eNum;
  stepBy = step;
  stmnt = b;
  if(!Type::isNumericType(c->type) || !Type::isNumericType(eNum->type)
  || !Type::isNumericType(sNum->type) || !Type::isNumericType(step->type))
  {
    Error* e = new Error();
    e->msg = "Expected a numeric type in roll(loop) statement";
    throw *e;
  }
}

Roll::~Roll()
{
  delete counter;
  delete startNum;
  delete endNum;
  delete stepBy;
  delete stmnt;
}

void Roll::printNode()
{
  printTabs();
  std::cerr << "========Roll Node========" << std::endl;
  Stmnt::printNode();
  tabs++;
  if(counter != NULL) counter->printNode();
  if(startNum != NULL) startNum->printNode();
  if(endNum != NULL) endNum->printNode();
  if(stepBy != NULL) stepBy->printNode();
  if(stmnt != NULL) stmnt->printNode();
  tabs--;
  printEndNode();
}
