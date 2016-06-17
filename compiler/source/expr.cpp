#include "expr.h"

void Expr::printNode()
{
  if(op != NULL) {printTabsClean(); std::cout << "Op:" << op->getString() << std::endl;}
  if(type != NULL){printTabsClean(); std::cout << "Type: " << type->getString() << std::endl;}
}
