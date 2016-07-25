#include "comp/const.h"
#include "symbols/type.h"
Const* Const::trueConst  = new Const(Word::BTrue,  Type::boolean);
Const* Const::falseConst = new Const(Word::BFalse, Type::boolean);

Const::Const(Token* o, Type* t) : Expr(o, t){}
Const::Const(int i) : Expr(new Number(i), Type::integer){}
Const::~Const(){}

void Const::jumping(int t, int f)
{
  std::stringstream ss;
  if (this == trueConst && t != 0){
    ss.str("");
    ss << "goto L" << t;
    emit(ss.str());
  }
  else if (this == falseConst && f != 0){
    ss.str("");
    ss << "goto L" << f;
    emit(ss.str());
  }
}

std::string Const::toString()
{
  if(type->getDataType() == Type::ch)
  {
    std::stringstream ss;
    //Quotes around STLIT or char literal
    if(op->tag == STLIT)
      ss << "\"" << Expr::toString() << "\"";
    else
      ss << "\'" << Expr::toString() << "\'";
    return ss.str();
  }
  else return Expr::toString();
}

void Const::printNode()
{
  printTabs();
  std::cerr << "========Const Node========" << std::endl;
  Expr::printNode();
  printEndNode();
}
