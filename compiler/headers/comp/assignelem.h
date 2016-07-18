#pragma once
#include "comp/stmnt.h"
#include "comp/arrayaccess.h"
#include "symbols/array.h"
class AssignElem : public Stmnt{
public:
  AssignElem(ArrayAccess* a, Expr* val);
  ~AssignElem();
  void gen(int b, int a);
  void printNode();
private:
  Expr* index;
  Expr* expr; //Must be same type as Id
  Id* array;
};
