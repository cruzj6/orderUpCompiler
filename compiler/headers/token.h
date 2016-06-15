#pragma once
#include "tag.h"
#include <list>
#include <string>
#include <sstream>
class Token{
public:
  int tag;
  std::string unknownToken;
  std::list<int> asciiValuesTag;
  Token(int t)
  {
    tag = t;
  }

  //For unknown tokens
  Token(std::string t)
  {
    //Get ascii for each character
    for(int i = 0; i < t.length(); i++)
    {
      //Give the tag some arbitrary value
      tag = -1;
      asciiValuesTag.push_back(t[i]);
    }

    unknownToken = t;
  }

  inline virtual std::string getString()
  {
    std::stringstream ss;
    if(asciiValuesTag.size() > 0)
    {
      ss << "TOKEN: Tag is ";
      std::list<int>::iterator it;
      for(it = asciiValuesTag.begin(); it != asciiValuesTag.end(); it++)
      {
        ss << static_cast<char>(*it);
      }
      ss << std::endl;

    }
    else ss << "TOKEN: Tag is " << static_cast<char>(tag) << std::endl;
    return ss.str();
  }

  virtual ~Token(){}
};
