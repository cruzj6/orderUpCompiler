#pragma once
#include "token.h"
#include <sstream>
class Number : public Token{
public:
  int value;
  Number(int num) : Token(NUM)
  {
      value = num;
  }

  inline std::string getString()
  {
    std::stringstream ss;
    ss << "NUMBER: value is " << value <<  " Tag is " << tag;
    return ss.str();
  }

  inline std::string getName()
  {
    std::stringstream ss;
    ss << value;
    return ss.str();
  }
};
