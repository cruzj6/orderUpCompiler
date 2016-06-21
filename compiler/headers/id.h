#pragma once
#include "expr.h"
#include "type.h"
class Id : public Expr{
private:
  int offset;

public:
  Id(Token* o, Type* t, int off) : Expr(o, t)
  {
    offset = off;
  }
  ~Id()
  {
  }
  Token* getToken();
  Type* getType();
  int getOffset();
  void printNode();
};
