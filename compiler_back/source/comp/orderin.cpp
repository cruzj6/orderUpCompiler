#include "comp/orderin.h"
#include "comp/temp.h"
void OrderIn::printNode()
{
  printTabs();
  std::cerr << "========OrderIn Node========" << std::endl;
  Expr::printNode();
  printEndNode();
}

Expr* OrderIn::gen()
{
  Temp* temp = new Temp(type);
  emit(temp->toString() + " = " + "sys_read");
  return temp;
}
