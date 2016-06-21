#pragma once
#include "op.h"

class Unary : public Op{
public:
  Expr* expr;
  Unary(Token* o, Expr* e) : Op(o, e->type)
  {
    expr = e;
  }
  ~Unary()
  {
    delete expr;
  }
  void printNode();
};
