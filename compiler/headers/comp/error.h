#pragma once
#include <string>
#include <exception>

class Error
{
public:
public:
    Error(){};
    ~Error(){};
    const char *ShowReason() const { return msg.c_str(); }
    std::string msg;
};
