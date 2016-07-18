#include "comp/node.h"
#include <sstream>
int Node::tabs = 0;
int Node::labels = 0;

void Node::printTabs()
{
  std::stringstream ss;
  ss << "|";
  for(int i = 0; i < tabs; i++)
  {
      if(i == tabs - 1) ss << tabs;
      else ss << "---";
  }
  std::cerr << ss.str();
}

void Node::printTabsClean()
{
  std::stringstream ss;
  ss<< "|";
  for(int i = 0; i < tabs; i++)
  {
    if(i == tabs - 1) ss << tabs << " ";
    else ss << "   ";
  }
  std::cerr << ss.str();
}

void Node::printEndNode()
{
  printTabs();
  std::cerr << "=======================" << "\n|" << std::endl;
}

int Node::newLabel()
{
  return ++labels;
}

void Node::emit(std::string codeString)
{
  std::cerr << "EMIT! " << codeString << std::endl;
  std::cout << "\t" << codeString << std::endl;
}

void Node::emitLabel(int i)
{
  std::cerr << "EMIT LABEL! " << i << std::endl;
  std::cout << "L" << i << ":" << std::endl;
}

void Node::emitFunctionLabel(std::string f)
{
  std::cout << f << ":" << std::endl;
}

void Node::emitFunctionEnd()
{
  std::cout << "END" << std::endl;
}
