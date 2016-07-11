#include "comp/functioncall.h"
#include "symbols/functionType.h"
#include "symbols/array.h"
#include "comp/error.h"
void FunctionCall::printNode()
{
  printTabs();
  std::cout << "========FunctionCall Node========" << std::endl;
  Expr::printNode();
  tabs++;
  std::vector<Expr*>::iterator it;
  for(it = params.begin(); it != params.end(); it++)
  {
    (*it)->printNode();
  }
  tabs--;
  printEndNode();
}

bool FunctionCall::checkTypes(std::vector<Expr*> exprs)
{
  FunctionType* ft = (FunctionType*)func->type;
  return ft->checkAgainstParamTypes(exprs);
}
