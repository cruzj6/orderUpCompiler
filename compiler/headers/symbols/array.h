#pragma once
#include "lexer/token.h"
#include "symbols/type.h"
#include <string>

class Array : public Type{
private:
  int numElem;
  Type* type;

public:
  Array(Type* t, int num);
  ~Array();
  std::string getString();
  std::string getName();
  Type* getDataType();

  void setNumElem(int num);
  int getWidth();
};
