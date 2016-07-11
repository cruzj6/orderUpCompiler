#pragma once
#include "comp/stmnt.h"
#include "comp/id.h"
#include <vector>

class Function : public Stmnt{
public:
  Function(std::vector<Id*> ps, Stmnt* blck, Type* rType){
    params = ps;
    funcBlock = blck;
    retType = rType;
  }
  void printNode();
  ~Function(){
    std::vector<Id*>::iterator it;
    for(it = params.begin(); it != params.end(); it++)
    {
      delete *it;
    }
    delete funcBlock;
  }
private:
  std::vector<Id*> params;
  Stmnt* funcBlock;
  Type* retType;
};
