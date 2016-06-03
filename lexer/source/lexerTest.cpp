#include "lexer.h"
#include "word.h"
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
  if(argc <= 1)
  {
    cout << "Please provide input file" << endl;
    exit(0);
  }

  Lexer* lexer = new Lexer();
  //lexer->printMap();
  lexer->begin(argv[1]);
  while(!lexer->getIsEOF())
  {
    cout << lexer->scan()->getString() << endl;
  }

  delete lexer;
  return 0;
}
