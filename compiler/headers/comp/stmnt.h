#pragma once
#include "comp/node.h"
#include "comp/error.h"
#include "lexer/Number.h"
#include <stdio.h>
#include <vector>

//Statement Containers
class Stmnt : public Node{
public:
  static Stmnt* Enclosing;
  virtual ~Stmnt(){}
  void printNode();
};
