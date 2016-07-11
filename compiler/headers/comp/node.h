#pragma once
#include <iostream>
class Node{
protected:
  int lexline;
  static int tabs;

public:
  virtual void printNode(){std::cout << "NODE! ERROR" << std::endl;}
  void printTabs();
  void printTabsClean();
  void printEndNode();
  virtual ~Node(){};
};
