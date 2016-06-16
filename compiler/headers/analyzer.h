#pragma once
#include "id.h"
#include "lexer.h"
#include "stmnt.h"
#include "env.h"
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
