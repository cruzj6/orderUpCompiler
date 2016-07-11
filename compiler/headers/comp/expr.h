#pragma once
#include "comp/node.h"
#include "symbols/type.h"
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
