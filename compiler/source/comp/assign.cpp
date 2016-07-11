#include "comp/assign.h"

Assign::Assign(Id* i, Expr* val)
{
  expr = val;
  id = i;
  Type* t = checkType(id->type->getDataType(), expr->type->getDataType());
  //We don't have matching types
  if(t == NULL)
  {
    Error* e = new Error();
    e->msg = "Assignment type does not match!";
    throw *e;
  }
  else{
    //Check our widths, in case this is strlit assignment, or array <- array
    Type* a = id->type;
    if(a->width < expr->type->width && a->width > a->getDataType()->width)
    {
      std::stringstream ss;
      ss << "Array not big enough to hold value!";
      expr->printNode();
      Error* e = new Error();
      e->msg = ss.str();
      throw *e;
    }
    //Check if we are trying to assign non array to an array
    if(expr->type->width == t->getDataType()->width && a->width > a->getDataType()->width)
    {
      Error* e = new Error();
      e->msg = "Cannot assign non-array to array";
      throw *e;
    }
  }
}

Assign::~Assign(){
  delete expr;
  delete id;
}

void Assign::printNode()
{
  printTabs();
  std::cout << "========Assign Node========" << std::endl;
  Stmnt::printNode();
  tabs++;
  if(expr != NULL) expr->printNode();
  if(id != NULL) {id->printNode();}
  tabs--;
  printEndNode();
}

Type* Assign::checkType(Type* t1, Type* t2)
{
  if(Type::isNumericType(t1) && Type::isNumericType(t2))
  {
    return t2;
  }
  else if(t1 == Type::boolean && t2 == Type::boolean){
    return t2;
  }
  else if(t1 == Type::ch && t2 == Type::ch)
  {
    return t2;
  }
  else
  {
    Array* a1 = dynamic_cast<Array*>(t1);
    Array* a2 = dynamic_cast<Array*>(t2);

    //If this is a string, we dont specify index, so make sure both are string
    if(a1 && a1->getDataType() == Type::ch && a2 && a2->getDataType() == Type::ch)
      {
        return a2;
      }
  }

  return NULL;
}
