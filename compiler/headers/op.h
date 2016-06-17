#pragma once
#include "expr.h"

class Op : public Expr{
public:
  Op(Token* o, Type* t) : Expr(o, t){}
  void printNode();
};
