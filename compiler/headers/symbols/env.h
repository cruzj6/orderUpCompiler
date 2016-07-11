#pragma once
#include "symbols/type.h"
#include "symbols/functionType.h"
#include "comp/id.h"
#include "comp/stmnt.h"
#include <map>

class Env{
private:

public:
  Env* prev;
  std::map<Token*, Id*> symbolTableMap;
  Env(Env* pre)
  {
    prev = pre;
  }
  ~Env()
  {
    //clean up map
    std::map<Token*, Id*>::iterator it;
    for(it = symbolTableMap.begin(); it != symbolTableMap.end(); it++)
    {
      delete it->first;
      delete it->second;
    }
  }

  void addSymbol(Token* tok, Id* id);
  Id* getIdForToken(Token* tok);
};
