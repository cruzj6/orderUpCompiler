#pragma once
#include "comp/expr.h"
#include "symbols/array.h"
class OrderIn : public Expr{
public:
  OrderIn(int size) : Expr(NULL, new Array(Type::ch, size))
  {

  }
  void printNode();
  Expr* gen();
};
