#pragma once
#include <iostream>
class Node{
protected:
  int lexline;

public:
  virtual void printNode(){std::cout << "NODE! ERROR" << std::endl;}
};
