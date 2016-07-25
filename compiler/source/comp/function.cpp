#include "comp/function.h"

Function::Function(Id* fId, std::vector<Id*> ps, Stmnt* blck, Type* rType){
  params = ps;
  funcBlock = blck;
  retType = rType;
  funcId = fId;
}

Function::~Function(){
  std::vector<Id*>::iterator it;
  for(it = params.begin(); it != params.end(); it++)
  {
    delete *it;
  }
  delete funcBlock;
}

void Function::gen(int b, int a)
{
  //Emit Procedure label
  emitFunctionLabel(funcId->toString());
  std::vector<Id*>::iterator it;
  for(it = params.begin(); it != params.end(); it++)
  {
    (*it)->gen();
  }

  //TODO: Return addr label something
  funcBlock->gen(0, a);
  emitFunctionEnd();

}

void Function::printNode()
{
  printTabs();
  std::cerr << "========Function Node========" << std::endl;
  Stmnt::printNode();
  tabs++;
  if(retType != NULL) std::cerr << retType->getString() << std::endl;
  std::vector<Id*>::iterator it;
  for(it = params.begin(); it != params.end(); it++)
  {
    (*it)->printNode();
  }
  if(funcBlock != NULL) funcBlock->printNode();
  tabs--;
  printEndNode();
}
