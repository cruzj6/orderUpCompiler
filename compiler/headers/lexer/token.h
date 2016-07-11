#pragma once
#include "lexer/tag.h"
#include <list>
#include <string>
#include <sstream>
class Token{
public:
  int tag;
  std::string unknownToken;
  std::list<int> asciiValuesTag;

public:
  Token(int t);
  Token(std::string t);  //For unknown tokens
  virtual std::string getName();
  virtual std::string getString();
  virtual ~Token(){}
};
