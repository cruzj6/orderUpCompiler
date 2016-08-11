#include "comp/temp.h"

int Temp::countFp = 0;
int Temp::count = 0;
std::string Temp::addrDesc[10] = {""};

Temp::Temp(Type* p) : Expr(Word::temp, p){
  if(p != Type::floating)
    {
    number = ++count;
    if(number == 9)
    {
      count = 0;
    }
  }
  else
  {
    countFp += 2;
    number = countFp;
    if(countFp == 30)
    {
      countFp = 0;
    }
  }
  /*if(number == 9)
  {
    number = 0;
  }*/
  //number = getReg(name);
}

int Temp::getReg(std::string name)
{
  for(int i = 0; i < 10; i++)
  {
    //already stored
    if(addrDesc[i] == name) return number;
  }
  if(addrDesc[number] == ""){
    //Free register
    return ++number;
  }
  else{
    //Store old to memory
    std::stringstream ss;
    ss << "sw $t" << number << ", " << addrDesc[number];
    emit(ss.str());
    addrDesc[number] = name;
    return number;
  }
}

std::string Temp::toString(){
  if(type == Type::floating)
  {
    std::stringstream ss;
    ss << "$f" << number;
    return ss.str();
  }
  else{
    std::stringstream ss;
    ss << "$t" << number;
    return ss.str();
  }
}
