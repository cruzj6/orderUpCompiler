#pragma once
class Real : public Token{
public:
    float value;
    Real(float num) : Token(FLOATING)
    {
      value = num;
    }

    std::string getString()
    {
      std::stringstream ss;
      ss << "REAL: value is " << value <<  " Tag is " << tag;
      return ss.str();
    }
};
