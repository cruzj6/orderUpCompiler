#include <iostream>
#include "error.h"
#include "analyzer.h"

int main(int argc, char* argv[])
{
  Analyzer* a = new Analyzer();
  a->setInfilePath(argv[1]);
  try{
    a->program();
  }
  catch(Error e)
  {
    std::cerr << "ERROR: " << e.ShowReason() << std::endl;
    exit(-1);
  }
}
