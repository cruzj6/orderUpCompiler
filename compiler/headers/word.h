#pragma once
#include "token.h"

class Word : public Token{
public:
  Word(std::string l, int t) : Token(t)
  {
    lexeme = l;
  }
  std::string lexeme;

  //Constant Words, based on EBNF
  static Word* LogicAnd;
  static Word* LogicOr;
  static Word* BTrue;
  static Word* BFalse;
  static Word* Break;
  static Word* BlockStart;
  static Word* BlockEnd;
  static Word* GroupStart;
  static Word* GroupEnd;
  static Word* Assign;
  static Word* AssignType;
  static Word* Plus;
  static Word* Minus;
  static Word* Eq;
  static Word* Neq;
  static Word* Le;
  static Word* Ge;
  static Word* LessThan;
  static Word* GreaterThan;
  static Word* Div;
  static Word* Mult;
  static Word* LineEnd;
  static Word* RetStmnt;
  static Word* ParamSep;
  static Word* Mod;

  //Loop Operators
  static Word* ASep;
  static Word* FlowOp;

  inline std::string getString()
  {
    std::stringstream ss;
    std::string str = lexeme;
    str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
    ss << "WORD: lexeme is " << str <<  " | Tag is " << tag;
    return ss.str();
  }

  //Destructor
  virtual ~Word(){}
};
