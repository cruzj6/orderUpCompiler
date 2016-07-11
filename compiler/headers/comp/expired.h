#pragma once
#include "comp/stmnt.h"

class Expired : public Stmnt{
public:
  Expired(Stmnt* st)
  {
    blockStmnt = st;
  }
  void printNode();
  ~Expired(){
    delete blockStmnt;
  }
private:
  Stmnt*  blockStmnt;
};