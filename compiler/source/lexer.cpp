#include "lexer.h"
#include <iostream>
#include <fstream>
#include <sstream>

void Lexer::buildDefaults()
{
  //Reserve Types
  reserve(Type::ch);
  reserve(Type::integer);
  reserve(Type::floating);
  reserve(Type::boolean);
  reserve(Type::function);

  //Reserve this as a word, special case
  //reserve(new Word("breakfastItems", STRING));

  //Reserve base words (operators)
  reserve(Word::LogicAnd);
  reserve(Word::LogicOr);
  reserve(Word::BTrue);
  reserve(Word::BFalse);
  reserve(Word::Break);
  reserve(Word::BlockStart);
  reserve(Word::BlockEnd);
  reserve(Word::GroupStart);
  reserve(Word::GroupEnd);
  reserve(Word::Assign);
  reserve(Word::AssignType);//@
  reserve(Word::Plus);
  reserve(Word::Minus);
  reserve(Word::Eq);
  reserve(Word::Neq);
  reserve(Word::Le);
  reserve(Word::Ge);
  reserve(Word::Div);
  reserve(Word::Mult);
  reserve(Word::ASep);
  reserve(Word::FlowOp);
  reserve(Word::LessThan);
  reserve(Word::GreaterThan);
  reserve(Word::Div);
  reserve(Word::Mult);
  reserve(Word::Mod);
  reserve(Word::ParamSep);
  reserve(Word::RetStmnt);
  reserve(Word::LineEnd);

  //Reserve word type terminals
  reserve(new Word("serveOut", OUT));
  reserve(new Word("orderIn", IN));
  reserve(new Word("fresh", IF));
  reserve(new Word("?fresh", ELSEIF));
  reserve(new Word("expired", ELSE));
  reserve(new Word("roll", FOR));
  reserve(new Word("stepBy", STEP));
  reserve(new Word("orderOf", RETTYPE));
  reserve(new Word("fresh", IF));
}

void Lexer::begin(std::string filePath)
{
  //Open the file
  inFile.open(filePath);
  readNextCh();
}

void Lexer::reserve(Word* w)
{
  //Reserve a word to save our keywords
  words[w->lexeme] = w;
}

void Lexer::printMap()
{
  std::map<std::string, Token*>::iterator it;
  for(it = words.begin(); it != words.end(); it++){
    std::cout << it->second->getString() << std::endl;
  }
}

//Read the next character from the input stream
void Lexer::readNextCh()
{
  peek = inFile.get();
  if(inFile.eof()) isEOF = true;
  //std::cout << "Next Char: " << peek << std::endl;
}

bool Lexer::readNextChCheck(char c)
{
  readNextCh();

  //Check if we get the expected character next
  if(peek == c) {peek = ' '; return true;}
  else return false;
}

Token* Lexer::scan()
{
  //Loop until it's not whitespace
  while(true)
  {
    if(peek == '\n') curLine++;
    else if(peek != ' ' && peek != '\t') break;

    if(isEOF) return new Token(ENDOFFILE);
    //Get the next character
    readNextCh();
  }

  /******************* Operators *******************/
  if(peek == '{') {readNextCh(); return Word::BlockStart;}
  else if(peek == '}') {readNextCh(); return Word::BlockEnd;}
  else if(peek == '(') {readNextCh(); return Word::GroupStart;}
  else if(peek == ')') {readNextCh(); return Word::GroupEnd;}
  else if(peek == '&'){
    if(readNextChCheck('&')) return Word::LogicAnd;
    else return new Token('&');
  }

  else if(peek == '|') {
    if(readNextChCheck('|')) return Word::LogicOr;
    else return new Token('&');
  }

  else if(peek == '<')
  {
    readNextCh();
    if(peek == '-') {readNextCh(); return Word::Assign;}
    else if(peek == '=')
    {
      readNextCh();
      //This may be equality operator so far '<='
      if(peek == '=')
      {
        //Now we have '<=='
        if(readNextChCheck('>')) return Word::Eq; //got the full <==>
        else {return new Token("<==");} //This is just a weird token
      }
      //We may have inequality '<=' so far
      else if(peek == '!')
      {
        //Now we have '<=!'
        if(readNextChCheck('='))
        {
          //Now we have '<=!='
          if(readNextChCheck('>')) return Word::Neq; //Full inequality '<=!=>'
          else return new Token("<=!=");

        } else return new Token("<=!");
      } else return Word::Le;
    } else return Word::LessThan;
  }

  else if(peek == '>')
  {
    readNextCh();
    if(peek == '=') return Word::Ge;
    else return Word::GreaterThan;
  }

  else if(peek == '+')
  {
    readNextCh();
    return Word::Plus;
  }

  else if(peek == '-')
  {
    if(readNextChCheck('>')) return Word::FlowOp;
    else return Word::Minus;
  }

  else if(peek == '*')
  {
    readNextCh();
    return Word::Mult;
  }

  else if(peek == '/')
  {
    //If this is a comment skip until new line
    if(readNextChCheck('/'))
    {
      while(peek != '\n')
      {
        readNextCh();
      }
      return scan(); //Go Again, no need to return anything for comment
    }
    //Multiline comments
    else if(peek == '*')
    {
      while(true)
      {
        readNextCh();
        if(peek == '\n') curLine++;
        if(peek == '*')
        {
          readNextCh();
          if(peek == '/')
          {
            readNextCh();
            //Go again, ignored the comment
            return scan();
          }
        }
      }
    }
    else return Word::Div;
  }
  else if(peek == ':')
  {
    readNextCh();
    return Word::ASep;
  }
  else if(peek == '@')
  {
    readNextCh();
    return Word::AssignType;
  }
  else if(peek == ';')
  {
    readNextCh();
    return Word::LineEnd;
  }
  else if(peek == ',')
  {
    readNextCh();
    return Word::ParamSep;
  }
  else if(peek == '%')
  {
    readNextCh();
    return Word::Mod;
  }
  /******************* End of Operators *******************/

  /******************* Numbers *******************/
  if(isdigit(peek))
  {
    std::stringstream ss;
    bool isReal = false;
    while(isdigit(peek))
    {
      ss << peek;
      readNextCh();
      if(peek == '.')
      {
        isReal = true;
        ss << '.';
        readNextCh();

        //This is incorrect token to be a number or a float
        if(!isdigit(peek)) return new Token(stoi(ss.str()));
      }
    }

    //Return real or number
    if(isReal) {
      std::string::size_type sz;
      float num = std::stof (ss.str(),&sz);
      return new Real(num);
    }
    else{
      return new Number(stoi(ss.str()));
    }
  }
  /******************* End Numbers *******************/

  /******************* Words *******************/
  if(isalpha(peek) || peek == '?')
  {
    std::stringstream ss;
    if(peek == '?') {ss << '?'; readNextCh();}
    while(isalpha(peek) || isdigit(peek))
    {
      ss << peek;
      readNextCh();
    }

    std::string identifier = ss.str();
    std::map<std::string, Token*>::iterator it;
    it = words.find(identifier);

    //If it is already in the map return it
    if(it != words.end())
    {
      return words[identifier];
    }
    else
    {
      //If not create it and return it
      words[identifier] = new Word(identifier, ID);
      return words[identifier];
    }
  }
  /******************* End Words *******************/

  //String literals
  if(peek == '\"')
  {
    std::stringstream ss;
    //Go until we hit a non-escaped quotation
    while(!readNextChCheck('\"'))
    {
      //If this is an escaped character
      if(peek == '\\' )
      {
        if(readNextChCheck('\"')) ss << "\"";
        else if(peek == 'n') ss << "\n";
        else if(peek == 't') ss << "\t";
      }
      else ss << peek;
    }
    return new Word(ss.str(), STLIT);
  }

  //No identification for the token given
  if(isEOF) return new Token(ENDOFFILE);
  else {
    char temp = peek;
    readNextCh();
    return new Token((int)temp);
  }

}

bool Lexer::getIsEOF()
{
  return isEOF;
}
