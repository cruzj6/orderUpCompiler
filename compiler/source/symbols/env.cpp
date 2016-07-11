#include "symbols/env.h"
#include <map>
#include <iostream>

void Env::addSymbol(Token* tok, Id* id)
{
  #ifdef DEBUG
  std::cout << "ADDING SYMBOL: " << tok->getString() << std::endl;
  #endif

  if(symbolTableMap.find(tok) == symbolTableMap.end())
    symbolTableMap[tok] = id;
}

void printSymTableIds()
{
  std::map<Token*, Id*>::iterator it;
}

Id* Env::getIdForToken(Token* tok)
{
  #ifdef DEBUG
  std::cout << "GETTING ID FOR TOKEN: " << tok->getString() << std::endl;
  #endif

  Env* curEnv = this;
  do{
    std::map<Token*, Id*>::iterator it;
    it =  curEnv->symbolTableMap.find(tok);
    if(it != curEnv->symbolTableMap.end())
    {
      #ifdef DEBUG
      std::cout << "FOUND!"<< std::endl;
      std::cout << it->second->type->getString() << std::endl;
      #endif

      return it->second;
    }
    curEnv = curEnv->prev;
  }while(curEnv != NULL);

  #ifdef DEBUG
  std::cout << "NOT FOUND!"<< std::endl;
  #endif

  return NULL;

}
