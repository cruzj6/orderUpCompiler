#pragma once
#include "comp/stmnt.h"
#include "comp/arrayaccess.h"
#include "symbols/array.h"
class AssignElem : public Stmnt{
public:
  AssignElem(ArrayAccess* a, Expr* val)
  {
    array = a->array;
    expr = val;
    index = a->index;
    if(array->type->getDataType() != val->type->getDataType())
    {
      Error* e = new Error();
      e->msg = "Value type does not match element type";
      throw *e;
    }
  }
  ~AssignElem()
  {
    delete index;
    delete expr;
    delete array;
  }
  void printNode();
private:
  Expr* index;
  Expr* expr; //Must be same type as Id
  Id* array;
};
