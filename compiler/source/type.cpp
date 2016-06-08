#include "type.h"

//Build the static Type objects
Type* Type::str = new Type("breakfastItems", BASICTYPE, 1);
Type* Type::ch = new Type("breakfastItem", BASICTYPE, 1);
Type* Type::integer = new Type("wholeMilk", BASICTYPE, 4);
Type* Type::floating = new Type("percentMilk", BASICTYPE, 8);
Type* Type::boolean = new Type("percentMilk", BASICTYPE, 1);
