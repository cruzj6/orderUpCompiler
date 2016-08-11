#include "comp/arrayaccess.h"

ArrayAccess::ArrayAccess(Id* i, Expr* e, Type* t) : Op(new Word("[]", INDEX), t)
{
  array = i;
  index = e;
}

ArrayAccess::~ArrayAccess()
{
  delete array;
  delete index;
}

void ArrayAccess::jumping(int t, int f)
{
  emitJumps(reduce()->toString(), t, f);
}

Expr* ArrayAccess::gen()
{
  return new ArrayAccess(array, index->reduce(), type);
}

std::string ArrayAccess::toString()
{
  std::stringstream ss;
  ss << array->toString() << + "[" << index->toString() << "]";
  return ss.str();
}

void ArrayAccess::printNode()
{
  printTabs();
  std::cerr << "========ArrayAccess Node========" << std::endl;
  Op::printNode();
  tabs++;
  if(array != NULL) array->printNode();
  if(index != NULL) index->printNode();
  tabs--;
  printEndNode();
}
