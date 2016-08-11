#pragma once
#include "token.h"
#include <sstream>

class Real : public Token{
public:
    float value;
    Real(float num);
    std::string getString();
    std::string getName();
    std::string toString();
};
