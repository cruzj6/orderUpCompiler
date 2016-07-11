#include <iostream>
#include "comp/error.h"
#include "comp/analyzer.h"

int main(int argc, char* argv[])
{
  Analyzer* a = new Analyzer();
  a->setInfilePath(argv[1]);
  try{
    a->program();
  }
  catch(Error e)
  {
    std::cerr << "\033[1;31mERROR: \033[0m" << e.ShowReason() << std::endl;
    delete a;
    exit(-1);
  }

  delete a;
}
