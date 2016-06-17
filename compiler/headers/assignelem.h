#pragma once
#include "stmnt.h"
#include "arrayaccess.h"
class AssignElem : public Stmnt{
public:
  AssignElem(ArrayAccess* a, Expr* val)
  {
    array = a->array;
    expr = val;
    index = a->index;
  }
  void printNode();
private:
  Expr* index;
  Expr* expr; //Must be same type as Id
  Id* array;
};
