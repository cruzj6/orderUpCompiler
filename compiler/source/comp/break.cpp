#include "comp/break.h"

Break::Break(){
  if(Stmnt::Enclosing == NULL)
  {
    Error* e = new Error();
    e->msg = "Break is not enclosed!";
    throw *e;
  }

  stmnt = Stmnt::Enclosing;
}

void Break::gen(int b, int a)
{
  std::stringstream ss;
  ss << "goto L" << stmnt->after;
  emit(ss.str());
}

void Break::printNode()
{
  printTabs();
  std::cerr << "========Break Node========" << std::endl;
  Stmnt::printNode();
}
