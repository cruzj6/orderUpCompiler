#pragma once
#include "comp/id.h"
#include "comp/op.h"

class ArrayAccess : public Op{
public:
  Id* array;
  Expr* index;
  ArrayAccess(Id* i, Expr* e, Type* t) : Op(new Word("[]", INDEX), t)
  {
    array = i;
    index = e;
  }
  ~ArrayAccess()
  {
    delete array;
    delete index;
  }
  void printNode();
};
