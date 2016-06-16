#include "token.h"
#include "type.h"
#include "stmnt.h"
#include <iostream>

Type* Arithmetic::checkType(Expr* e1, Expr* e2)
{
  if(e1->type == Type::floating || e2->type == Type::floating)
  {
    return Type::floating;
  }
  return Type::integer;
}

Const* Const::trueConst  = new Const(Word::BTrue,  Type::boolean);
Const* Const::falseConst = new Const(Word::BFalse, Type::boolean);

Token* Id::getToken()
{
  return op;
}

Type* Id::getType()
{
  return type;
}

int Id::getOffset()
{
  return offset;
}

/************************************
Functions for printing each Node Type
*************************************/
int tabs = 0;
void printTabs()
{
  std::stringstream ss;
  ss << "|";
  for(int i = 0; i < tabs; i++)
  {
      if(i == tabs - 1) ss << tabs;
      else ss << "---";
  }
  std::cout << ss.str();
}

void printTabsClean()
{
  std::stringstream ss;
  ss<< "|";
  for(int i = 0; i < tabs; i++)
  {
    if(i == tabs - 1) ss << tabs << " ";
    else ss << "   ";
  }
  std::cout << ss.str();
}

void printEndNode()
{
  printTabs();
  std::cout << "=======================" << "\n|" << std::endl;
}

void Expr::printNode()
{
  if(op != NULL) {printTabsClean(); std::cout << "Op:" << op->getString() << std::endl;}
  if(type != NULL){printTabsClean(); std::cout << "Type: " << type->getString() << std::endl;}
}

void Id::printNode()
{
  printTabs();
  std::cout << "========Id Node========\n" ;
  printTabsClean();
  std::cout << "Offset: " << offset << std::endl;
  Expr::printNode();
  printEndNode();
}

void OrderIn::printNode()
{
  printTabs();
  std::cout << "========OrderIn Node========" << std::endl;
  Expr::printNode();
  printEndNode();
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
  printEndNode();
  tabs--;
}

void LogicExpr::printNode()
{
  printTabs();
  std::cout << "========LogicExpr Node========" << std::endl;
  Expr::printNode();
  tabs++;
  if(op1 != NULL) op1->printNode();
  if(op2 != NULL) op2->printNode();
  printEndNode();
  tabs--;
}

void Not::printNode()
{
  printTabs();
  std::cout << "========Not Node========" << std::endl;
  LogicExpr::printNode();
  printEndNode();
}

void OrLogicExpr::printNode()
{
  printTabs();
  std::cout << "========OrLogicExpr Node========" << std::endl;
  LogicExpr::printNode();
  printEndNode();
}

void AndLogicExpr::printNode()
{
  printTabs();
  std::cout << "========AndLogicExpr Node========" << std::endl;
  LogicExpr::printNode();
  printEndNode();
}

void LogicRelExpr::printNode()
{
  printTabs();
  std::cout << "========LogicRelExpr Node========" << std::endl;
  LogicExpr::printNode();
  printEndNode();
}

void Const::printNode()
{
  printTabs();
  std::cout << "========Const Node========" << std::endl;
  Expr::printNode();
  printEndNode();
}

void Op::printNode()
{
  printTabs();
  std::cout << "========Op Node========" << std::endl;
  Expr::printNode();
  printEndNode();
}

void ArrayAccess::printNode()
{
  printTabs();
  std::cout << "========ArrayAccess Node========" << std::endl;
  Op::printNode();
  tabs++;
  if(array != NULL) array->printNode();
  if(index != NULL) index->printNode();
  printEndNode();
  tabs--;
}

void Unary::printNode()
{
  printTabs();
  std::cout << "========Unary Node========" << std::endl;
  Op::printNode();
  tabs++;
  if(expr != NULL) expr->printNode();
  printEndNode();
  tabs--;
}

void Stmnt::printNode()
{

}

void Return::printNode()
{
  printTabs();
  std::cout << "========Return Node========" << std::endl;
  Stmnt::printNode();
  tabs++;
  if(ret != NULL) ret->printNode();
  printEndNode();
  tabs--;
}

void Break::printNode()
{
  printTabs();
  std::cout << "========Break Node========" << std::endl;
  Stmnt::printNode();
}

void Seq::printNode()
{
  printTabs();
  std::cout << "========Seq Node========" << std::endl;
  Stmnt::printNode();
  tabs++;
  if(st1 != NULL) st1->printNode();
  if(st2 != NULL) st2->printNode();
  printEndNode();
  tabs--;
}

void ServeOut::printNode()
{
  printTabs();
  std::cout << "========ServeOut Node========" << std::endl;
  Stmnt::printNode();
  tabs++;
  if(outExpr != NULL) outExpr->printNode();
  printEndNode();
  tabs--;
}

void Assign::printNode()
{
  printTabs();
  std::cout << "========Assign Node========" << std::endl;
  Stmnt::printNode();
  tabs++;
  if(expr != NULL) expr->printNode();
  if(id != NULL) id->printNode();
  printEndNode();
  tabs--;
}

void AssignElem::printNode()
{
  printTabs();
  std::cout << "========AssignElem Node========" << std::endl;
  Stmnt::printNode();
  if(index != NULL) index->printNode();
  if(expr != NULL) expr->printNode();
  if(array != NULL) array->printNode();
  printEndNode();
}

void Roll::printNode()
{
  printTabs();
  std::cout << "========Roll Node========" << std::endl;
  Stmnt::printNode();
  tabs++;
  if(counter != NULL) counter->printNode();
  if(startNum != NULL) startNum->printNode();
  if(endNum != NULL) endNum->printNode();
  if(stepBy != NULL) stepBy->printNode();
  if(stmnt != NULL) stmnt->printNode();
  printEndNode();
  tabs--;
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
  printEndNode();
  tabs--;
}

void QFresh::printNode()
{
  printTabs();
  std::cout << "========QFresh Node========" << std::endl;
  Stmnt::printNode();
  tabs++;
  if(booleanExpr != NULL) booleanExpr->printNode();
  if(stmnt != NULL) stmnt->printNode();
  if(chainStmnt != NULL) chainStmnt->printNode();
  printEndNode();
  tabs--;
}

void Expired::printNode()
{
  printTabs();
  std::cout << "========Expired Node========" << std::endl;
  Stmnt::printNode();
  tabs++;
  if(blockStmnt != NULL) blockStmnt->printNode();
  printEndNode();
  tabs--;
}

void Function::printNode()
{
  printTabs();
  std::cout << "========Function Node========" << std::endl;
  Stmnt::printNode();
  tabs++;
  if(retType != NULL) std::cout << retType->getString() << std::endl;
  std::vector<Id*>::iterator it;
  for(it = params.begin(); it != params.end(); it++)
  {
    (*it)->printNode();
  }
  if(funcBlock != NULL) funcBlock->printNode();
  std::cout << "=======================" << std::endl;
  tabs--;
}
