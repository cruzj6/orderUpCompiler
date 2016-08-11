#include "comp/functionstmnt.h"
#include "comp/functioncall.h"

FunctionStmnt::FunctionStmnt(Expr* call)
{
  funcCall = call;
}

FunctionStmnt::~FunctionStmnt(){
  delete funcCall;
}

void FunctionStmnt::gen(int b, int a)
{
  std::stringstream ss;
  std::vector<Expr*>::iterator it;
  for(it = ((FunctionCall*)funcCall)->getParams().begin(); it != ((FunctionCall*)funcCall)->getParams().end(); it++)
  {
    ss.str("");
    ss << "param " << (*it)->gen()->toString();
    emit(ss.str());
  }

  //Func call
  std::cerr << std::endl;
  ss.str("");
  ss << "call " << ((FunctionCall*)funcCall)->getFunc()->toString();
  emit(ss.str());
}

void FunctionStmnt::printNode()
{
  printTabs();
  std::cerr << "========FunctionStmnt Node========" << std::endl;
  Stmnt::printNode();
  tabs++;
  if(funcCall != NULL) funcCall->printNode();
  tabs--;
  printEndNode();
}
