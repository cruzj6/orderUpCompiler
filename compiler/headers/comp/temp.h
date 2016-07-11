#pragma once
#include "comp/expr.h"

//No Id just a inline num or strlit or whatever
class Temp : public Expr{
public:
  Word* tempToken;
};
