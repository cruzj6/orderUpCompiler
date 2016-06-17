#pragma once
#include "id.h"
#include "lexer.h"
#include "stmnt.h"
#include "env.h"
#include "arrayaccess.h"
#include "seq.h"
#include "functionid.h"
#include "function.h"
#include "roll.h"
#include "fresh.h"
#include "break.h"
#include "return.h"
#include "serveout.h"
#include "assign.h"
#include "functioncall.h"
#include "functionstmnt.h"
#include "assignelem.h"
#include "qfresh.h"
#include "expired.h"
#include "orlogicexpr.h"
#include "andlogicexpr.h"
#include "logicrelexpr.h"
#include "arithmetic.h"
#include "unary.h"
#include "not.h"
#include "const.h"
#include "orderin.h"
#include <string>

class Analyzer{
public:
  Analyzer()
  {

  }
  void program();
  void match(int toMatch);
  void move();
  void setInfilePath(std::string p);

  //Non-terminals
  void throwError(std::string msg);
  Stmnt* functions();
  Stmnt* function();
  Stmnt* block();
  Stmnt* stmnts();
  Stmnt* stmnt();
  Stmnt* Else();
  Stmnt* br();
  Expr* expr();
  Expr* sum();
  void declarations();
  void declaration();
  Expr* boolean();
  Expr* logicBool();
  Expr* equality();
  Expr* equalityOp();
  Expr* mult();
  Expr* mod();
  Expr* unary();
  Expr* factor();
  ArrayAccess* offset(Id* id);
  Type* type();
  ~Analyzer(){
    delete lexer;
    delete top;
    delete curToken;
  }
private:
  Lexer* lexer;
  Env* top;
  Token* curToken;
  std::string curInFilePath;
  int used;
};
