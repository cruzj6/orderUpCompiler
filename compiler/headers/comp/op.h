#pragma once
#include "comp/expr.h"

class Op : public Expr{
public:
  Op(Token* o, Type* t) : Expr(o, t){}
  void printNode();
};
