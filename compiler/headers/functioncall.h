#pragma once
#include "expr.h"
#include <vector>

class FunctionCall : public Expr{
public:
  FunctionCall(Token* tok, Type* t, std::vector<Expr*> exps) : Expr(tok, t)
  {
    params = exps;
  }
  ~FunctionCall(){
    std::vector<Expr*>::iterator it;
    for(it = params.begin(); it != params.end(); it++)
    {
      delete *it;
    }
  }
  void printNode();
private:
  std::vector<Expr*> params;
};
