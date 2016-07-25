#include "comp/serveout.h"
#include "comp/temp.h"

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
  emit(tBuff->toString() + " = " + outExpr->toString());
  ss << "len " << outExpr->type->width;
  emit(ss.str());
  emit("buffer " + tBuff->toString());
  emit("sys_write");
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
