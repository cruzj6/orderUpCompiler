#include "comp/temp.h"

int Temp::count = 0;

Temp::Temp(Type* p) : Expr(Word::temp, p){
  number = ++count;
}

std::string Temp::toString(){
  std::stringstream ss;
  ss << "t" << number;
  return ss.str();
}
