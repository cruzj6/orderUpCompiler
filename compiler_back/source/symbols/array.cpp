#include "symbols/array.h"
#include "symbols/type.h"
#include <iostream>

Array::Array(Type* t, int num) : Type(t->lexeme, t->tag, num * t->width)
{
  numElem = num;
  type = t;
}

Array::~Array()
{
  delete type;
}

void Array::setNumElem(int num)
{
  numElem = num;
}

int Array::getWidth()
{
  return width;
}

std::string Array::getString()
{
  std::stringstream ss;
  ss << "Array: type is " << lexeme <<  " | Tag is " << tag << "."
      << " | Width is "<< getWidth();
  return ss.str();
}

std::string Array::getName()
{
  return lexeme;
}

std::string Array::toString()
{
  std::cerr << "ARRAY TO STRING" << std::endl;
  if(getDataType() == Type::ch)
  {
    std::stringstream ss;
    ss << "\"" << lexeme << "\"";
    return ss.str();
  }
  else Word::toString();
}

Type* Array::getDataType()
{
  if(type != NULL)
    return type->getDataType();
  else return NULL;
}
