#pragma once
#include "comp/id.h"
#include "comp/stmnt.h"
#include "symbols/array.h"
#include "symbols/functionType.h"

class Assign : public Stmnt{
public:
  Assign(Id* i, Expr* val);
  ~Assign();
  void printNode();
  Type* checkType(Type* t1, Type* t2);
  void gen(int b, int a);
private:
  Expr* expr; //Must be same type as Id
  Id* id;
};
