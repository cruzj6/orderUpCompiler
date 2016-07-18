#include "lexer/real.h"

Real::Real(float num) : Token(FLOATING)
{
  value = num;
}

std::string Real::getString()
{
  std::stringstream ss;
  ss << "REAL: value is " << value <<  " Tag is " << tag;
  return ss.str();
}

std::string Real::getName()
{
  std::stringstream ss;
  ss << value;
  return ss.str();
}

std::string Real::toString()
{
  std::stringstream ss;
  ss << value;
  return ss.str();
}
