#pragma once
#include "comp/stmnt.h"

class OrderUp : public Stmnt{
public:
  Expr* expr; //Expression we are returning
  ~OrderUp()
  {
    delete expr;
  }
  void printNode();
};
