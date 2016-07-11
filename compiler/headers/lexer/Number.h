#pragma once
#include "lexer/token.h"
#include <sstream>
class Number : public Token{
public:
  int value;
  Number(int num);
  std::string getString();
  std::string getName();
};
