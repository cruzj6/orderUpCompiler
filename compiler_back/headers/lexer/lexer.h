#pragma once
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <list>
#include "symbols/array.h"
#include "lexer/Number.h"
#include "lexer/real.h"
#include "symbols/type.h"

class Lexer{
public:
  int curLine;
  Token* scan();
  Lexer();

  //Public functions
  void reserve(Word* w);
  void buildDefaults();
  void printMap();
  void begin(std::string filePath);
  void getNextToken();
  bool getIsEOF();

  //Destructor
  ~Lexer();
  
private:
  std::map<std::string, Token*> words;
  std::ifstream inFile;
  char peek;
  bool isEOF;

  //Private functions
  void readNextCh();
  bool readNextChCheck(char c);

};
