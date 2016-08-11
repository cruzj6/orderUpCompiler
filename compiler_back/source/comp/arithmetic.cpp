#include "comp/arithmetic.h"
#include "comp/error.h"
#include "comp/temp.h"
#include "comp/analyzer.h"

Arithmetic::Arithmetic(Token* o, Expr* e1, Expr* e2) : Op(o, checkType(e1, e2)){
  op1 = e1;
  op2 = e2;
}
Arithmetic::~Arithmetic()
{
  delete op1;
  delete op2;
}

void Arithmetic::printNode()
{
  printTabs();
  std::cerr << "========Arithmetic Node========" << std::endl;
  Expr::printNode();
  tabs++;
  if(op1 != NULL) {
    op1->printNode();
  }
  if(op2 != NULL) {
    op2->printNode();
  }
  tabs--;
  printEndNode();
}

// constructs RHS of three-address instruction
// by reducing operands to addresses
Expr* Arithmetic::gen()
{
  return new Arithmetic(op, op1->reduce(), op2->reduce());
}

std::string Arithmetic::toString()
{
  std::cerr << "\nARITH NODE TO STRING" << std::endl;

  Temp* temp1 = new Temp(op1->type);
  Temp* temp = new Temp(type);
  Temp* temp2 = new Temp(op2->type);

  bool isReg1 = op1->toString().find_first_of('$') != std::string::npos;
  bool isFP1 = op1->type == Type::floating;
  if(!isReg1){
    emit((Analyzer::is_number(op1->toString()) ?
        (op1->toString().find_first_of('.') == std::string::npos ? "li " : "li.s ")
      : (op1->type == Type::floating ? "l.s " : "lw ")) +
        temp1->toString() + ", " + op1->toString());
  }
  else{
    emit((isFP1 ? "mov.s " : "move ") + temp1->toString() + ", " + op1->toString());
  }

  bool isReg2 = op2->toString().find_first_of('$') != std::string::npos;
  bool isFP2 = op2->type == Type::floating;
  if(!isReg2){
    emit((Analyzer::is_number(op2->toString()) ?
        (op2->toString().find_first_of('.') == std::string::npos ? "li " : "li.s ")
      : (op2->type == Type::floating ? "l.s " : "lw ")) +
       temp2->toString() + ", " + op2->toString());
   }
   else{
     emit((isFP2 ? "mov.s " : "move ") + temp2->toString() + ", " + op2->toString());
   }

  //Convert to mips
  std::string opMips;
  bool isFP = (temp1->type == Type::floating || temp2->type == Type::floating);
  if(op->toString() == "*")
  {
    emit("mult " + temp1->toString() + ", " + temp2->toString());
    emit("mflo " + temp->toString());
  }
  else if(op->toString() == "/")
  {
    emit("div " + temp1->toString() + ", " + temp2->toString());
    emit("mflo " + temp->toString());
  }
  else if(op->toString() == "+")
  {
    emit((!isFP ? "move " : "mov.s ") + temp->toString() + ", " + temp1->toString());
    emit((!isFP ? "add " : "add.s ") + temp->toString() + ", " + temp->toString() + ", " + temp2->toString());
  }
  else if(op->toString() == "-")
  {
    emit((!isFP ? "move " : "mov.s ") + temp->toString() + ", " + temp1->toString());
    emit((!isFP ? "sub " : "sub.s ") + temp->toString() + ", " + temp->toString() + ", " + temp2->toString());
  }
  else if(op->toString() == "%")
  {
    emit((!isFP ? "move " : "mov.s ") + temp->toString() + ", " + temp1->toString());
    emit((!isFP ? "rem " : "rem.s ") + temp->toString() + ", " + temp->toString() + ", " + temp2->toString());
  }
  return temp->toString();
}

Type* Arithmetic::checkType(Expr* e1, Expr* e2)
{
  std::cerr << e1->type->getString() << e2->type->getString() << std::endl;
  if(!Type::isNumericType(e1->type) || !Type::isNumericType(e2->type))
  {
    Error* e = new Error();
    e->msg = "Expected numeric expression";
    throw *e;
  }
  else if(e1->type == Type::floating || e2->type == Type::floating)
  {
    return Type::floating;
  }
  return Type::integer;
}
