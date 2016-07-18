#include <iostream>
#include <fstream>
#include <unistd.h>
#include <libgen.h>
#include "comp/error.h"
#include "lexer/lexer.h"
#include "comp/analyzer.h"

int main(int argc, char* argv[])
{
  //Check our input file
  if(argc < 2)
  {
    std::cerr << "\033[1;31mERROR: \033[0m" << "Input File Required" << std::endl;
    exit(-1);
  }

  //Convert to string to check extensions and validity
  std::string fileString(argv[1]);
  if(access(argv[1], F_OK) != 0)
  {
    std::cerr << "\033[1;31mERROR: \033[0m" << "Invalid Input File" << std::endl;
    exit(-1);
  }
  else if(fileString.substr(fileString.length() - 4, 4) != ".oup")
  {
    std::cerr << "\033[1;31mERROR: \033[0m" << "Requires *.oup File" << std::endl;
    exit(-1);
  }

  std::string fileName = basename(argv[1]);
  std::string dir = dirname(argv[1]);
  fileName.erase(fileName.length() - 4, 4);

  //Change output to the intermediate code file
  std::string outFile = "./temp/" + fileName + ".i";
  std::cerr << outFile << std::endl;
  std::ofstream out;
  out.open(outFile, std::ofstream::out);
  std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

  //std::cin.rdbuf(cinbuf);   //reset to standard input again
  //std::cout.rdbuf(coutbuf); //reset to standard output again

  //If it's good proceed with parsing
  Lexer* lex = new Lexer();
  Analyzer* a = new Analyzer();
  a->setInfilePath(argv[1]);
  fileString.erase(fileString.length() - 4, 4);
  try{
    a->program(lex);
  }
  catch(Error e)
  {
    std::cerr << "\033[1;31mERROR: \033[0m" << e.ShowReason() << std::endl;
    delete a;
    exit(-1);
  }

  delete a;
  return 0;
}
