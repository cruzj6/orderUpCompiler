#pragma once
#include "comp/stmnt.h"

class Break : public Stmnt{
public:
  Break();
  void printNode();
  void gen(int b, int a);
  Stmnt* stmnt;
};
