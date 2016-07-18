#include "comp/assignelem.h"
void AssignElem::printNode()
{
  printTabs();
  std::cerr << "========AssignElem Node========" << std::endl;
  Stmnt::printNode();
  if(index != NULL) index->printNode();
  if(expr != NULL) expr->printNode();
  if(array != NULL) array->printNode();
  printEndNode();
}

void AssignElem::gen(int b, int a)
{
  // Reduce index expression to an address (if it's not already)
  std::string s1 = index->reduce()->toString();

  std::cerr << "SEP " << "S1: " << s1 << std::endl;

  // Reduce RHS expression to an address (if it's not already)
  std::string s2 = expr->reduce()->toString();

  std::stringstream arrayString;
  arrayString << array->toString() << " [ " << s1 ;//<< " ] = " << s2;
  // Print code for array element access. Example: a[t2] = t3
  emit(arrayString.str());
}

AssignElem::AssignElem(ArrayAccess* a, Expr* val)
{
  array = a->array;
  expr = val;
  index = a->index;
  if(array->type->getDataType() != val->type->getDataType())
  {
    Error* e = new Error();
    e->msg = "Value type does not match element type";
    throw *e;
  }
}

AssignElem::~AssignElem()
{
  delete index;
  delete expr;
  delete array;
}
