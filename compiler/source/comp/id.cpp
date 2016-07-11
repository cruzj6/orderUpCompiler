#include "comp/id.h"

void Id::printNode()
{
  printTabs();
  std::cout << "========Id Node========" << std::endl;
  printTabsClean();
  std::cout << "Offset: " << offset << std::endl;
  Expr::printNode();
  printEndNode();
}

Token* Id::getToken()
{
  return op;
}

Type* Id::getDataType()
{
  return type;
}

int Id::getOffset()
{
  return offset;
}
