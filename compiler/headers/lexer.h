#pragma once
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <list>
#include "type.h"
#include "number.h"
#include "real.h"
#include "array.h"

class Lexer{
public:
  int curLine;
  Token* scan();

  Lexer(){
    curLine = 1;
    isEOF = false;
    buildDefaults();
  };

  //Public functions
  void reserve(Word* w);
  void buildDefaults();
  void printMap();
  void begin(std::string filePath);
  void getNextToken();
  bool getIsEOF();


  //Destructor
  inline ~Lexer(){
      //This should get rid of everything in the Words and types too as
      //they are reserved
      std::map<std::string, Token*>::iterator it;
      for(it = words.begin(); it != words.end(); it++){
        delete it->second;
      }

      inFile.close();
  }
private:
  std::map<std::string, Token*> words;
  std::ifstream inFile;
  char peek;
  bool isEOF;

  //Private functions
  void readNextCh();
  bool readNextChCheck(char c);

};
