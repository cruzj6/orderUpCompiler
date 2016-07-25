#include "comp/roll.h"
#include "comp/temp.h"
#include "comp/logicrelexpr.h"
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

void Roll::gen(int b, int a)
{
  after = a;

  Temp* start = new Temp(startNum->type);
  Temp* end = new Temp(endNum->type);

  //Temp for start num
  std::stringstream sStart;
  sStart << start->toString() << " = " << startNum->toString();
  emit(sStart.str());

  //Start counter at start number
  sStart.str("");
  sStart << counter->toString() << " = " << start->toString();
  emit(sStart.str());

  //Temp for end num
  std::stringstream sEnd;
  sEnd << end->toString() << " = " << endNum->toString();
  emit(sEnd.str());

  //Check for loop fall through
  int labelCheckLoop = newLabel();
  emitLabel(labelCheckLoop);

  //Emit compare, create temporary relExpr
  LogicRelExpr* relExpr = new LogicRelExpr(Word::Ge, counter, end);
  relExpr->jumping(a, 0); //If it is greater than or equal to our end number, were done

  //Label where loop counter is incremented
  int labelInc = newLabel();
  //label & code for stmt
  int label = newLabel();
  emitLabel(label);
  stmnt->gen(label, labelInc);

  //Emit Increment the counter
  emitLabel(labelInc);
  sStart.str("");
  sStart << counter->toString() << " = " << counter->toString() << " + " << stepBy->toString();
  emit(sStart.str());

  //Go back to start to check loop
  std::stringstream goStart;
  goStart << "goto L" << labelCheckLoop;
  emit(goStart.str());	// jump to beginning of roll(loop)
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
