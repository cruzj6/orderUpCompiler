#pragma once
#include "comp/expr.h"
#include "comp/id.h"
#include <vector>

class FunctionCall : public Expr{
public:

  FunctionCall(Token* tok, Type* t, std::vector<Expr*> exps, Id* funcCalled);
  ~FunctionCall();
  bool checkTypes(std::vector<Expr*> exprs);
  void printNode();
  Expr* gen();
  std::vector<Expr*> getParams();
  Id* getFunc();

private:
  std::vector<Expr*> params;
  Id* func;
};
