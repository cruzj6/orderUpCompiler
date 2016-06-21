#pragma once
#include "node.h"
#include "type.h"
//Expression containers
class Expr : public Node{
public:
  Expr(Token* o, Type* t)
  {
    op = o;
    type = t;
  }
  virtual ~Expr()
  {
    delete op;
    delete type;
  }
  Token* op;
  Type* type; //What this statement "returns"
  void printNode();
};
