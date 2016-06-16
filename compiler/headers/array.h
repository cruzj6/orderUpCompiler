#pragma once
#include "token.h"
#include "type.h"
#include <string>

class Array : public Type{
private:
  int numElem;
  int width;
  Type* type;

public:
  Array(Type* t, int num) : Type(t->lexeme, t->tag, num * t->width)
  {
    numElem = num;
    type = t;
  }

  inline std::string getString()
  {
    std::stringstream ss;
    ss << "Array: type is " << lexeme <<  " | Tag is " << tag << "."
        << " | Width is "<< getWidth();
    return ss.str();
  }

  void setNumElem(int num);
  int getWidth();
};
