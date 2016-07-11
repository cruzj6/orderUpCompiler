#pragma once
#include "lexer/token.h"
#include "lexer/Number.h"
#include "comp/expr.h"

class Const : public Expr{
public:
  Const(Token* o, Type* t) : Expr(o, t){}
  Const(int i) : Expr(new Number(i), Type::integer){}
  ~Const(){

  }
  void printNode();
  static Const* trueConst;
  static Const* falseConst;
};
