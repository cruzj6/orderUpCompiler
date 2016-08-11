#pragma once
#include "comp/stmnt.h"
#include "comp/id.h"

class Roll : public Stmnt{
public:
  Roll();
  void printNode();
  void init(Id* c, Expr* sNum, Expr* eNum, Expr* step, Stmnt* b);
  ~Roll();
private:
  Id* counter;
  Expr* startNum; //Must be wholeMilk/integer type
  Expr* endNum; //Must be  wholeMilk/integer type
  Expr* stepBy; //Must be  wholeMilk/integer type
  Stmnt* stmnt;
  void gen(int b, int a);
};
