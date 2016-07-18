#include "lexer/Number.h"
#include <iostream>

Number::Number(int num) : Token(NUM)
{
    value = num;
}

std::string Number::getString()
{
  std::stringstream ss;
  ss << "NUMBER: value is " << value <<  " Tag is " << tag;
  return ss.str();
}

std::string Number::getName()
{
  std::stringstream ss;
  ss << value;
  return ss.str();
}

std::string Number::toString()
{
  std::cerr << "Number to string: " << value << std::endl;
  std::stringstream ss;
  ss << value;
  std::cerr << ss.str() << std::endl;
  return ss.str();
}
