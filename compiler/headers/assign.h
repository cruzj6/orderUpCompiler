#pragma once
#include "id.h"
#include "stmnt.h"

class Assign : public Stmnt{
public:
  Assign(Id* i, Expr* val)
  {
    expr = val;
    id = i;
  }
  ~Assign(){
    delete expr;
    delete id;
  }
  void printNode();
private:
  Expr* expr; //Must be same type as Id
  Id* id;
};
