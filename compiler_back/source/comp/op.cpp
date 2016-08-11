#include "comp/op.h"
#include "comp/temp.h"
#include "comp/analyzer.h"

Op::Op(Token* o, Type* t) : Expr(o, t){

}

Expr* Op::reduce()
{
  Expr* x = gen();          // Generate term (depends on type of op)
  Temp* t = new Temp(type); // Create temp to hold result of op
  bool isNum = Analyzer::is_number(x->toString());
  bool isFP = isNum && x->toString().find_first_of('.') != std::string::npos;
  emit((isNum ? "li " : "move ") + t->toString() + ", " + x->toString());
  return t;
}

void Op::printNode()
{
  printTabs();
  std::cerr << "========Op Node========" << std::endl;
  Expr::printNode();
  printEndNode();
}
