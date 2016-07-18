#include "symbols/env.h"
#include <map>
#include <iostream>

void Env::addSymbol(Token* tok, Id* id)
{
  #ifdef DEBUG
  std::cerr << "ADDING SYMBOL: " << tok->getString() << std::endl;
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
  std::cerr << "GETTING ID FOR TOKEN: " << tok->getString() << std::endl;
  #endif

  Env* curEnv = this;
  do{
    std::map<Token*, Id*>::iterator it;
    it =  curEnv->symbolTableMap.find(tok);
    if(it != curEnv->symbolTableMap.end())
    {
      #ifdef DEBUG
      std::cerr << "FOUND!"<< std::endl;
      std::cerr << it->second->type->getString() << std::endl;
      #endif

      return it->second;
    }
    curEnv = curEnv->prev;
  }while(curEnv != NULL);

  #ifdef DEBUG
  std::cerr << "NOT FOUND!"<< std::endl;
  #endif

  return NULL;

}
