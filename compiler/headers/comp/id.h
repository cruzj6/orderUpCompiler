#pragma once
#include "comp/expr.h"
#include "symbols/type.h"
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
  Type* getDataType();
  int getOffset();
  void printNode();
};
