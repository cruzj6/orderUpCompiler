#pragma once
#include "type.h"
#include "id.h"
#include "stmnt.h"
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

  void addSymbol(Token* tok, Id* id);
  Id* getIdForToken(Token* tok);
};
