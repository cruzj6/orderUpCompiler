#include "comp/node.h"
#include <sstream>
int Node::tabs = 0;

void Node::printTabs()
{
  std::stringstream ss;
  ss << "|";
  for(int i = 0; i < tabs; i++)
  {
      if(i == tabs - 1) ss << tabs;
      else ss << "---";
  }
  std::cout << ss.str();
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
  std::cout << ss.str();
}

void Node::printEndNode()
{
  printTabs();
  std::cout << "=======================" << "\n|" << std::endl;
}
