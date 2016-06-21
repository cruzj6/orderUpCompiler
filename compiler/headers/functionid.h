#pragma once
#include "id.h"

class FunctionId : public Id{
public:
  Type* retType;
  FunctionId(Token*o, Type* t, int off, Type* ret) : Id(o, t, off)
  {
    retType = ret;
  }
  ~FunctionId()
  {
    delete retType;
  }
  void printNode();
};
