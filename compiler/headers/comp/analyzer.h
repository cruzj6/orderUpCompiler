#pragma once
#include "comp/id.h"
#include "lexer/lexer.h"
#include "comp/stmnt.h"
#include "symbols/env.h"
#include "comp/arrayaccess.h"
#include "comp/seq.h"
#include "comp/function.h"
#include "comp/roll.h"
#include "comp/fresh.h"
#include "comp/break.h"
#include "comp/return.h"
#include "comp/serveout.h"
#include "comp/assign.h"
#include "comp/functioncall.h"
#include "comp/functionstmnt.h"
#include "comp/assignelem.h"
#include "comp/qfresh.h"
#include "comp/expired.h"
#include "comp/orlogicexpr.h"
#include "comp/andlogicexpr.h"
#include "comp/logicrelexpr.h"
#include "comp/arithmetic.h"
#include "comp/unary.h"
#include "comp/not.h"
#include "comp/const.h"
#include "comp/orderin.h"
#include <string>
#include <fstream>

class Analyzer{
public:
  Analyzer()
  {

  }
  void program(Lexer* lex);
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
