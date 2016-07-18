#include "lexer/word.h"

//Build all of our static words
Word* Word::LogicAnd = new Word("&&", AND);
Word* Word::LogicOr = new Word("||", OR);
Word* Word::BTrue = new Word("bacon", TRU);
Word* Word::BFalse = new Word("sausage", FALS);
Word* Word::Break = new Word("break", BREAK);
Word* Word::BlockStart = new Word("{", BLOCKSTART);
Word* Word::BlockEnd = new Word("}", BLOCKEND);
Word* Word::GroupStart = new Word("(", GROUPSTART);
Word* Word::GroupEnd = new Word(")", GROUPEND);
Word* Word::Assign = new Word("<-", ASSIGN);
Word* Word::AssignType = new Word("@", ASSIGNTYPE);//@
Word* Word::Plus = new Word("+", PLUS);
Word* Word::Minus = new Word("-", MINUS);
Word* Word::Eq = new Word("<==>", EQ);
Word* Word::Neq = new Word("<=!=>", NEQ);
Word* Word::Le = new Word("<=", LE);
Word* Word::Ge = new Word(">=", GE);
Word* Word::Div = new Word("/", DIV);
Word* Word::Mult = new Word("*", MULT);
Word* Word::LessThan = new Word("<", LESSTHAN);
Word* Word::GreaterThan = new Word(">", GREATERTHAN);
Word* Word::RetStmnt = new Word("orderUp", RETSTMNT);
Word* Word::LineEnd = new Word(";", LINEEND);
Word* Word::ParamSep = new Word(",", PARAMSEP);
Word* Word::Mod = new Word("%", MOD);

//Loop Operators
Word* Word::ASep = new Word(":", ASEP);
Word* Word::FlowOp = new Word("->", FLOW);
Word* Word::temp = new Word("t", TEMP);

Word::Word(std::string l, int t) : Token(t)
{
  lexeme = l;
}

std::string Word::getString()
{
  std::stringstream ss;
  std::string str = lexeme;
  str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
  ss << "WORD: lexeme is " << str <<  " | Tag is " << tag;
  return ss.str();
}

std::string Word::toString()
{
  return lexeme;
}

std::string Word::getName()
{
  return lexeme;
}
