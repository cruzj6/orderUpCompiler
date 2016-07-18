#pragma once
#include "comp/stmnt.h"

class Expired : public Stmnt{
public:
  Expired(Stmnt* st);
  ~Expired();
  void printNode();
  void gen(int b, int a);
private:
  Stmnt*  blockStmnt;
};
