#pragma once
#include "stmnt.h"
#include "id.h"

class Roll : public Stmnt{
public:
  Roll()
  {
    counter = NULL;
    startNum = NULL;
    endNum = NULL;
    stepBy = NULL;
    stmnt = NULL;
  }
  void printNode();

  void init(Id* c, Expr* sNum, Expr* eNum, Expr* step, Stmnt* b)
  {
    counter = c;
    startNum = sNum;
    endNum = eNum;
    stepBy = step;
    stmnt = b;
  }
  ~Roll()
  {
    delete counter;
    delete startNum;
    delete endNum;
    delete stepBy;
    delete stmnt;
  }
private:
  Id* counter;
  Expr* startNum; //Must be wholeMilk/integer type
  Expr* endNum; //Must be  wholeMilk/integer type
  Expr* stepBy; //Must be  wholeMilk/integer type
  Stmnt* stmnt;
};
