#pragma once
#include "word.h"

class Type : public Word{
public:
  int width;
  static Type* ch;
  static Type* integer;
  static Type* floating;
  static Type* boolean;
  static Type* function;

  Type(std::string l, int t, int w) : Word(l,t)
  {
    Word(l, t);
    width = w;
  }

  inline std::string getString()
  {
    std::stringstream ss;
    ss << "TYPE: lexeme is " << lexeme <<  " | Tag is " << tag << "."
        << " | Width is "<< width;
    return ss.str();
  }

  inline std::string getName()
  {
    return lexeme;
  }
};
