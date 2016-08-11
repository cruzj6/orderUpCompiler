#include "symbols/functionType.h"

FunctionType::FunctionType(Type* retType, std::vector<Type*> paramTypes)
: Type(retType != NULL ? retType->lexeme : "", FUNC, 0)
{
  rType = retType;
  pTypes = paramTypes;
  std::vector<Type*>::iterator it;

  //Build the size of the function based on params and retType
  for(it = pTypes.begin(); it != pTypes.end(); it++)
  {
    width += (*it)->width;
  }

  if(retType != NULL)
    width += retType->width;
}

FunctionType::~FunctionType()
{
  delete rType;
}

Type* FunctionType::getDataType(){
  if(rType != NULL)
    return rType->getDataType();
  else
    return NULL;
}

std::string FunctionType::getString()
{
  std::stringstream ss;
  ss << "Function: return type is " << (lexeme == "" ? "void" : lexeme) <<  " | Tag is " << tag << "."
      << " | Width is "<< width;
  return ss.str();
}

Type* FunctionType::getTypeForParamPos(int pos){
  return pTypes[pos];
}

bool FunctionType::checkAgainstParamTypes(std::vector<Expr*> exprs)
{
  std::vector<Type*>::iterator it;
  if(pTypes.size() != exprs.size())
  {
    Error* e = new Error();
    e->msg = "Differing number of paramaters from function signature";
    throw *e;
  }

  //Check if each param is same type
  for(it = pTypes.begin(); it != pTypes.end(); it++)
  {
    int i = distance(pTypes.begin(), it);
    if(*it != exprs[i]->type)
    {
      //Check if these are array params
      Array* a1 = dynamic_cast<Array*>(exprs[i]->type);
      Array* a2 = dynamic_cast<Array*>(*it);

      //Check if the array types are the same
      if(a1 != NULL && a2!= NULL && a1->getDataType() ==  a2->getDataType())
      {
        //If array we are passing is too big
        if(a2->width >= a1->width)
        {
          continue;
        }
        else{
          Error* e = new Error();
          e->msg = "Array being passed is too large";
          throw *e;
        }
      }
      Error* e = new Error();
      e->msg = "Invalid parameter types for function call";
      throw *e;
    }
  }
}
