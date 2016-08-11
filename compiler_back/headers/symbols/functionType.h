#pragma once
#include "type.h"
#include "symbols/array.h"
#include "comp/error.h"
#include "comp/expr.h"
#include <iostream>
#include <vector>
#include <string>

class FunctionType : public Type{
public:
  FunctionType(Type* retType, std::vector<Type*> paramTypes);
  ~FunctionType();
  Type* getDataType();
  Type* getTypeForParamPos(int pos);
  std::string getString();
  bool checkAgainstParamTypes(std::vector<Expr*> exprs);

private:
  std::vector<Type*> pTypes;
  Type* rType;
};
