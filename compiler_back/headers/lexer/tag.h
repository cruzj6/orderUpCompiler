#pragma once
enum Tag{
  //Operators
  ASSIGN = 256,
  ASSIGNTYPE,
  PLUS,
  MINUS,
  EQ,
  NEQ,
  LE,
  GE,
  LESSTHAN,
  GREATERTHAN,
  DIV,
  MULT,
  MOD,
  LINEEND,

  //Loop Tags
  FOR,
  ASEP,
  FLOW,
  STEP,

  //Conditional and bool
  AND,
  OR,
  IF,
  ELSE,
  ELSEIF,
  TRU,
  FALS,

  //other
  BREAK,
  NUM,
  FLOATING,
  STLIT,
  STRING,
  ID,
  BASICTYPE,
  FUNC,
  PARAMSEP,
  RETTYPE,
  RETSTMNT,
  BLOCKSTART,
  BLOCKEND,
  GROUPSTART,
  GROUPEND,
  ENDOFFILE,
  OUT,
  IN,
  INDEX,
  TEMP
};
