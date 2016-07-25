#include "comp/expr.h"

Expr::Expr(Token* o, Type* t)
{
  op = o;
  type = t;
}
Expr::~Expr()
{
  delete op;
  delete type;
}

Expr* Expr::gen()
{
  return this;
}

Expr* Expr::reduce()
{
  std::cerr << "REDUCE" << std::endl;
  return this;
}

//Jumping for bools
void Expr::jumping(int t, int f)
{
  emitJumps(toString(), t, f);
}

void Expr::emitJumps(std::string test, int t, int f)
{
  std::stringstream emitStream;
  if (t != 0 &&  f != 0) {
    emitStream << "if " << test << " goto L" << t;
	  emit(emitStream.str());

    emitStream.str("");
    emitStream << "goto L" << f;
	  emit(emitStream.str());
  }
  else if (t != 0 ) {
    emitStream.str("");
    emitStream << "if " << test << " goto L" << t;
    emit(emitStream.str());
  }
  else if (f != 0 ) {
    emitStream.str("");
    emitStream << "iffalse " << test << " goto L" << f;
    emit(emitStream.str());
  }
  else ; // Nothing since both t and f fall through
}

std::string Expr::toString()
{
  if(op == NULL) return "";
  std::cerr << "GET EXPR STRING: " << op->toString() << std::endl;
  return op->toString();
}

void Expr::printNode()
{
  if(op != NULL) {printTabsClean(); std::cerr << "Op:" << op->getString() << std::endl;}
  if(type != NULL){printTabsClean(); std::cerr << "Type: " << type->getString() << std::endl;}
}
