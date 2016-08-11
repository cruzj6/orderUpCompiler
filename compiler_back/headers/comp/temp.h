#pragma once
#include "comp/expr.h"

//Used to store intermediate results, simulates register
class Temp : public Expr{
public:
  Temp(Type* p);
  std::string toString();
  static int count;
  int getReg(std::string name);
  static std::string addrDesc[10];
  int number = 0;
  static int countFp;
};
