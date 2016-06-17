#pragma once
#include "expr.h"
class OrderIn : public Expr{
public:
  OrderIn() : Expr(NULL, Type::ch)
  {

  }
  void printNode();
};
