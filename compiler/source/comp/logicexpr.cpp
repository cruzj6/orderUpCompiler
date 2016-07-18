#include "comp/logicexpr.h"
#include "comp/temp.h"

LogicExpr::LogicExpr(Token* o, Expr* e1, Expr* e2) : Expr(o, Type::boolean)
{
  op1 = e1;
  op2 = e2;
}

Expr* LogicExpr::gen()
{
  int f = newLabel();                 // Label for false code
  int a = newLabel();                 // Label for code after

  Temp* temp = new Temp(type);         //"register"/temp var
  jumping(0,f);                  //Fall through on true, jump on false

  // True case
  emit(temp->toString() + " = true");

  std::stringstream ss;
  ss << "goto L" << a;
  emit(ss.str());

  // False Case
  emitLabel(f);
  emit(temp->toString() + " = false");
  emitLabel(a);

  return temp;
}

std::string LogicExpr::toString()
{
  return op1->toString() + " " + op->toString() + " " + op2->toString();
}

LogicExpr::~LogicExpr()
{
  delete op1;
  delete op2;
}

void LogicExpr::printNode()
{
  printTabs();
  std::cerr << "========LogicExpr Node========" << std::endl;
  Expr::printNode();
  tabs++;
  if(op1 != NULL) op1->printNode();
  if(op2 != NULL) op2->printNode();
  tabs--;
  printEndNode();
}
