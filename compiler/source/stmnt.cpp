#include "token.h"
#include "type.h"
#include "stmnt.h"

Type* Arithmetic::checkType(Expr* e1, Expr* e2)
{
  if(e1->type == Type::floating || e2->type == Type::floating)
  {
    return Type::floating;
  }
  return Type::integer;
}

Const* Const::trueConst  = new Const(Word::BTrue,  Type::boolean);
Const* Const::falseConst = new Const(Word::BFalse, Type::boolean);

Token* Id::getToken()
{
  return op;
}

Type* Id::getType()
{
  return type;
}

int Id::getOffset()
{
  return offset;
}
