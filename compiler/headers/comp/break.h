#pragma once
#include "comp/stmnt.h"

class Break : public Stmnt{
public:
  Break(){
    if(Stmnt::Enclosing == NULL)
    {
      Error* e = new Error();
      e->msg = "Break is not enclosed!";
      throw *e;
    }
  }
  void printNode();
};
