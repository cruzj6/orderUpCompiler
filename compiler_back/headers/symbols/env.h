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
  Env(Env* pre);
  ~Env();

  void addSymbol(Token* tok, Id* id);
  Id* getIdForToken(Token* tok);
  void genSymbolTable();
  std::string getMIPSDataTypeName(Id* t);
};
