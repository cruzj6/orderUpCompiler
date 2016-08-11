#include "comp/logicrelexpr.h"
#include "comp/temp.h"

LogicRelExpr::LogicRelExpr(Token* o, Expr* e1, Expr* e2) : LogicExpr(o, e1, e2)
{}

void LogicRelExpr::printNode()
{
  printTabs();
  std::cerr << "========LogicRelExpr Node========" << std::endl;
  LogicExpr::printNode();
  printEndNode();
}

void LogicRelExpr::jumping(int t, int f)
{

  Expr* a = op1->reduce();
  Expr* b = op2->reduce();

  Temp* op1Reg = new Temp(a->type);
  Temp* op2Reg = new Temp(b->type);

  bool isFP = op1Reg->type == Type::floating || op2Reg->type == Type::floating;
  bool isReg = a->toString().find_first_of('$') != std::string::npos;
  if(!isReg) emit((isFP ? "l.s " : "lw ") + op1Reg->toString() + ", " + a->toString());
  else{
    emit((isFP ? "mov.s " : "move ") + op1Reg->toString() + ", " + a->toString());
  }
  //emit("lw " + op2Reg->toString() + ", " + b->toString());

  std::string eqal = "";
  std::string opString = op->toString();

  //Get the MIPS comparison op
  if(opString == ">=")
  {
    eqal = "bge";
  }
  else if(opString == "<=")
  {
    eqal = "ble";
  }
  else if(opString == "<==>")
  {
    eqal = "beq";
  }
  else if(opString == "<=!=>")
  {
    eqal = "bne";
  }
  else if(opString == ">")
  {
    eqal = "bgt";
  }
  else if(opString == "<")
  {
    eqal = "blt";
  }

  /*std::string test = a->toString() + " " + op->toString() + " " +
    (b->toString() == "" ? Word::BTrue->toString() : b->toString());*/

    std::string test = eqal + " " + op1Reg->toString() + ", " +
      (b->toString() == "" ? Word::BTrue->toString() : b->toString());

  emitJumps(test, t, f);
}
