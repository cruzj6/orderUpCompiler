#pragma once
#include "comp/stmnt.h"

class Seq : public Stmnt{
public:
  Stmnt* st1;
  Stmnt* st2;
  void printNode();
  Seq(Stmnt* s1, Stmnt* s2)
  {
    st1 = s1;
    st2 = s2;
  }
  ~Seq()
  {
    delete st1;
    delete st2;
  }
};
