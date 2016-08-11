#pragma once
#include "comp/op.h"

class Unary : public Op{
public:
  Expr* expr;
  Unary(Token* o, Expr* e);
  ~Unary();
  Expr* gen();
  void printNode();
  std::string toString();
};
