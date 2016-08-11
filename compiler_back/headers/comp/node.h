#pragma once
#include <iostream>
class Node{
protected:
  int lexline;
  static int tabs;
  static int labels;

public:
  virtual void printNode(){std::cerr << "NODE! ERROR" << std::endl;}
  void printTabs();
  void printTabsClean();
  void printEndNode();
  void emit(std::string codeString);
  void emitLabel(int i);
  int newLabel();
  void emitFunctionLabel(std::string f);
  void emitFunctionEnd();
  virtual ~Node(){};
};
