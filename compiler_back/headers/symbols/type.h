#pragma once
#include "lexer/word.h"

class Type : public Word{
public:
  int width;
  static Type* ch;
  static Type* integer;
  static Type* floating;
  static Type* boolean;

  Type(std::string l, int t, int w);
  std::string getString();
  std::string getName();
  virtual Type* getDataType();
  static bool isNumericType(Type* t);
};
