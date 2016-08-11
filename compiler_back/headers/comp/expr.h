#pragma once
#include "comp/node.h"
#include "symbols/type.h"
//Expression containers
class Expr : public Node{
public:
  Expr(Token* o, Type* t);
  virtual ~Expr();
  Token* op;
  Type* type; //What this statement "returns"
  void printNode();
  virtual Expr* gen();
  virtual Expr* reduce();
  virtual void jumping(int t, int f);
  virtual void emitJumps(std::string test, int t, int f);
  virtual std::string toString();
};
