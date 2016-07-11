#include "symbols/type.h"
#include <iostream>

//Build the static Type objects
Type* Type::ch = new Type("breakfastItem", BASICTYPE, 1);
Type* Type::integer = new Type("wholeMilk", BASICTYPE, 2);
Type* Type::floating = new Type("percentMilk", BASICTYPE, 4);
Type* Type::boolean = new Type("baconOrSausage", BASICTYPE, 1);

bool Type::isNumericType(Type* t)
{
  return (t == integer || t == floating);
}

Type::Type(std::string l, int t, int w) : Word(l,t)
{
  Word(l, t);
  width = w;
}

std::string Type::getString()
{
  std::stringstream ss;
  ss << "TYPE: lexeme is " << lexeme <<  " | Tag is " << tag << "."
      << " | Width is "<< width;
  return ss.str();
}

std::string Type::getName()
{
  return lexeme;
}

Type* Type::getDataType()
{
  return this;
}
