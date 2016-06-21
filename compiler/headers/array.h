#pragma once
#include "token.h"
#include "type.h"
#include <string>

class Array : public Type{
private:
  int numElem;
  Type* type;

public:
  Array(Type* t, int num) : Type(t->lexeme, t->tag, num * t->width)
  {
    numElem = num;
    type = t;
  }

  ~Array()
  {
    delete type;
  }

  inline std::string getString()
  {
    std::stringstream ss;
    ss << "Array: type is " << lexeme <<  " | Tag is " << tag << "."
        << " | Width is "<< getWidth();
    return ss.str();
  }

  inline std::string getName()
  {
    return lexeme;
  }

  void setNumElem(int num);
  int getWidth();
};
