#include "comp/functioncall.h"
#include "symbols/functionType.h"
#include "symbols/array.h"
#include "comp/error.h"
#include "comp/temp.h"

FunctionCall::FunctionCall(Token* tok, Type* t, std::vector<Expr*> exps, Id* funcCalled) : Expr(tok, t)
{
  params = exps;
  func = funcCalled;
  checkTypes(exps);
}

FunctionCall::~FunctionCall(){
  std::vector<Expr*>::iterator it;
  for(it = params.begin(); it != params.end(); it++)
  {
    delete *it;
  }
}

void FunctionCall::printNode()
{
  printTabs();
  std::cerr << "========FunctionCall Node========" << std::endl;
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

std::vector<Expr*> FunctionCall::getParams(){
  return params;
}

Id* FunctionCall::getFunc(){
  return func;
}

Expr* FunctionCall::gen()
{
  //Params
  std::stringstream ss;
  std::vector<Expr*>::iterator it;
  for(it = params.begin(); it != params.end(); it++)
  {
    ss.str("");
    ss << "param " << (*it)->gen()->toString();
    emit(ss.str());
  }

  //Result holder
  Temp* res = new Temp(type);
  ss.str("");
  ss << "result " << res->toString();
  emit(ss.str());

  //Func call
  ss.str("");
  ss << "call " << func->toString() << ", " << params.size();
  emit(ss.str());

  return res;
}

bool FunctionCall::checkTypes(std::vector<Expr*> exprs)
{
  FunctionType* ft = (FunctionType*)func->type;
  return ft->checkAgainstParamTypes(exprs);
}
