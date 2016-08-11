// tag.h
//

#ifndef LZZ_tag_h
#define LZZ_tag_h
#define LZZ_INLINE inline
enum Tag
{
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
  FOR,
  ASEP,
  FLOW,
  STEP,
  AND,
  OR,
  IF,
  ELSE,
  ELSEIF,
  TRU,
  FALS,
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
  INDEX
};
#undef LZZ_INLINE
#endif
