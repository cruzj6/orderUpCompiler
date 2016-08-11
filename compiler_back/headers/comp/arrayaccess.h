#pragma once
#include "comp/id.h"
#include "comp/op.h"

class ArrayAccess : public Op{
public:
  Id* array;
  Expr* index;
  ArrayAccess(Id* i, Expr* e, Type* t);
  ~ArrayAccess();
  Expr* gen();
  std::string toString();
  void jumping(int t, int f);
  void printNode();
};
