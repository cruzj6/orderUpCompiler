#pragma once
#include "comp/expr.h"
#include "comp/op.h"

//Type must be wholeMilk or percentMilk
class Arithmetic : public Op{
public:
  Arithmetic(Token* o, Expr* e1, Expr* e2);
  ~Arithmetic();
  Expr* op1;
  Expr* op2;
  void printNode();
  Expr* gen();
  std::string toString();
private:
  Type* checkType(Expr* e1, Expr* e2);
};
