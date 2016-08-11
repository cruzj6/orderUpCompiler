#pragma once
#include "lexer/token.h"

class Word : public Token{
public:
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

  static Word* temp;

  Word(std::string l, int t);
  std::string getString();
  std::string getName();
  std::string toString();

  //Destructor
  virtual ~Word(){}
};
