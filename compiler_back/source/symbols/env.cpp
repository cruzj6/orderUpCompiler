#include "symbols/env.h"
#include <map>
#include <iostream>

Env::Env(Env* pre)
{
  prev = pre;
}

Env::~Env()
{
  //clean up map
  std::map<Token*, Id*>::iterator it;
  for(it = symbolTableMap.begin(); it != symbolTableMap.end(); it++)
  {
    delete it->first;
    delete it->second;
  }
}

void Env::addSymbol(Token* tok, Id* id)
{
  #ifdef DEBUG
  std::cerr << "ADDING SYMBOL: " << tok->getString() << std::endl;
  #endif

  if(symbolTableMap.find(tok) == symbolTableMap.end())
    symbolTableMap[tok] = id;

  //Set up init for .data values, make sure we dont create for functions
  if(dynamic_cast<FunctionType*>(id->type) == NULL){
    std::stringstream hold;
    hold << " ";
    int num = 0;
    if(id->type->getDataType() != NULL){
        num = (id->type->width / id->type->getDataType()->width);
    }
    else {
      num = 1;
    }
    std::cerr << "\n\n\n\n\n\n\nNUMBER IS " << num << std::endl;
    for(int i = 0; i < num; i++)
    {
      hold << "0";
      if(i < num - 1) hold << ",";
    }
    std::cout << tok->toString() << ": ." << getMIPSDataTypeName(id)
      << hold.str() << std::endl;
  }
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

void Env::genSymbolTable(){
  std::cout << ".data" << std::endl;
}

std::string Env::getMIPSDataTypeName(Id* t)
{
  int width = 0;
  if(t->type->getDataType() != NULL){
    width = t->type->getDataType()->width;
  }
  else{
    width = t->getDataType()->width;
  }
  switch(width){
    case 1:
      return "byte";
      break;

    case 2:
      return "word";
      break;

    case 4:
      return "word";
      break;

    default:
      return "ERROR";
      break;
  }
}
