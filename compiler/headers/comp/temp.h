#pragma once
#include "comp/expr.h"

//Used to store intermediate results, simulates register
class Temp : public Expr{
public:
  Temp(Type* p);
  std::string toString();
  static int count;
  int number = 0;
};
