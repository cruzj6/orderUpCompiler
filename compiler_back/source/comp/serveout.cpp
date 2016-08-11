#include "comp/serveout.h"
#include "comp/temp.h"
#include "comp/analyzer.h"

ServeOut::ServeOut(Expr* out)
{
  outExpr = out;
}

ServeOut::~ServeOut()
{
  delete outExpr;
}

void ServeOut::gen(int b, int a)
{
  std::stringstream ss;
  Temp* tBuff = new Temp(outExpr->type);


  if(Analyzer::stlits.find(outExpr->toString()
    .substr(1, outExpr->toString().length() - 2)) != Analyzer::stlits.end()){
      emit("li $v0, 4");
      ss << "la $a0, str" << Analyzer::stlits[outExpr->toString().substr(1, outExpr->toString().length() - 2)];
  }
  else{
    emit("li $v0, 1");
    ss << "lw, $a0 " << outExpr->toString();
  }
  emit(ss.str());
  emit("syscall");

  /*emit(tBuff->toString() + " = " + outExpr->toString());
  ss << "len " << outExpr->type->width;
  emit(ss.str());
  emit("buffer " + tBuff->toString());
  emit("sys_write");*/
}

void ServeOut::printNode()
{
  printTabs();
  std::cerr << "========ServeOut Node========" << std::endl;
  Stmnt::printNode();
  tabs++;
  if(outExpr != NULL) outExpr->printNode();
  tabs--;
  printEndNode();
}
