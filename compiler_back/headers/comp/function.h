#pragma once
#include "comp/stmnt.h"
#include "comp/id.h"
#include <vector>

class Function : public Stmnt{
public:
  Function(Id* fId, std::vector<Id*> ps, Stmnt* blck, Type* rType);
  ~Function();
  void printNode();
  void gen(int b, int a);
private:
  std::vector<Id*> params;
  Stmnt* funcBlock;
  Type* retType;
  Id* funcId;
};
