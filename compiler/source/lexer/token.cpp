#include "lexer/token.h"
#include <iostream>

Token::Token(int t)
{
  tag = t;
}

//For unknown tokens
Token::Token(std::string t)
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

std::string Token::getString()
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
  }
  else ss << "TOKEN: Tag is " << static_cast<char>(tag);
  return ss.str();
}

std::string Token::toString()
{
  std::stringstream ss;
  ss << (char)tag;
  return  ss.str();
}

std::string Token::getName()
{
  std::stringstream ss;
  if(asciiValuesTag.size() > 0)
  {
    std::list<int>::iterator it;
    for(it = asciiValuesTag.begin(); it != asciiValuesTag.end(); it++)
    {
      ss << static_cast<char>(*it);
    }
  }
  else ss << static_cast<char>(tag);
  return ss.str();
}
