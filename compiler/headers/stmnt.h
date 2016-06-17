#pragma once
#include "node.h"
#include "error.h"
#include "Number.h"
#include <stdio.h>
#include <vector>

//Statement Containers
class Stmnt : public Node{
public:
  static Stmnt* Enclosing;
  virtual ~Stmnt(){}
  void printNode();
};
