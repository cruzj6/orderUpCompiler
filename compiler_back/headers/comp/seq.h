#pragma once
#include "comp/stmnt.h"

class Seq : public Stmnt{
public:
  Stmnt* st1;
  Stmnt* st2;
  void printNode();
  Seq(Stmnt* s1, Stmnt* s2);
  ~Seq();
  void gen(int b, int a);
};
