#pragma once
#include "comp/expr.h"

class Op : public Expr{
public:
  Op(Token* o, Type* t);
  Expr* reduce();
  void printNode();
};
