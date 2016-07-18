#include "comp/return.h"

Id* Return::curFuncBlock = NULL;

Return::Return(Expr* retExpr)
{
  Type* funcRetType = curFuncBlock->type->getDataType();
  if(curFuncBlock == NULL)
  {
    Error* e = new Error();
    e->msg = "No function to return from";
    throw *e;
  }
  else if(funcRetType == NULL && retExpr != NULL)
  {
    Error* e = new Error();
    e->msg = "Returned value from void function";
    throw *e;
  }
  else if(retExpr == NULL && funcRetType != NULL)
  {
    Error* e = new Error();
    e->msg = "At Return: Function is not void";
    throw *e;
  }
  else if(retExpr != NULL && funcRetType != retExpr->type->getDataType())
  {
    std::cerr << funcRetType->getString()<< std::endl;
    std::cerr << retExpr->type->getDataType()->getString() << std::endl;
    Error* e = new Error();
    e->msg = "Return Expression type does not match function return type";
    throw *e;
  }
  else ret = retExpr;
}

Return::~Return()
{
  delete ret;
}

void Return::printNode()
{
  printTabs();
  std::cerr << "========Return Node========" << std::endl;
  Stmnt::printNode();
  tabs++;
  if(ret != NULL) ret->printNode();
  tabs--;
  printEndNode();
}
