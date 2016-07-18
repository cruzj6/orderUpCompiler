#pragma once
#include "lexer/token.h"
#include "lexer/Number.h"
#include "comp/expr.h"

class Const : public Expr{
public:
  Const(Token* o, Type* t);
  Const(int i);
  ~Const();
  void jumping(int t, int f);
  void printNode();
  static Const* trueConst;
  static Const* falseConst;
};
