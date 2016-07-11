#pragma once
#include "comp/expr.h"
#include "comp/id.h"
#include <vector>

class FunctionCall : public Expr{
public:

  FunctionCall(Token* tok, Type* t, std::vector<Expr*> exps, Id* funcCalled) : Expr(tok, t)
  {
    params = exps;
    func = funcCalled;
    checkTypes(exps);
  }

  ~FunctionCall(){
    std::vector<Expr*>::iterator it;
    for(it = params.begin(); it != params.end(); it++)
    {
      delete *it;
    }
  }

  bool checkTypes(std::vector<Expr*> exprs);
  void printNode();
  
private:
  std::vector<Expr*> params;
  Id* func;
};
