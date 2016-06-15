#include "env.h"
#include <map>
#include <iostream>

void Env::addSymbol(Token* tok, Id* id)
{
  std::cout << "ADDING SYMBOL: " << tok->getString() << std::endl;
  if(symbolTableMap.find(tok) == symbolTableMap.end())
    symbolTableMap[tok] = id;
}

void printSymTableIds()
{
  std::map<Token*, Id*>::iterator it;
}

Id* Env::getIdForToken(Token* tok)
{
  std::cout << "GETTING ID FOR TOKEN: " << tok->getString() << std::endl;
  Env* curEnv = this;
  do{
    std::map<Token*, Id*>::iterator it;
    it =  curEnv->symbolTableMap.find(tok);
    if(it != curEnv->symbolTableMap.end())
    {
      std::cout << "FOUND!"<< std::endl;
      return it->second;
    }
    curEnv = curEnv->prev;
  }while(curEnv != NULL);

  std::cout << "NOT FOUND!"<< std::endl;
  return NULL;

}
