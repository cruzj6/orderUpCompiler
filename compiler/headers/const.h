#pragma once
#include "token.h"
#include "Number.h"
#include "expr.h"

class Const : public Expr{
public:
  Const(Token* o, Type* t) : Expr(o, t){}
  Const(int i) : Expr(new Number(i), Type::integer){}
  void printNode();
  static Const* trueConst;
  static Const* falseConst;
};
