#include "type.h"

//Build the static Type objects
Type* Type::ch = new Type("breakfastItem", BASICTYPE, 1);
Type* Type::integer = new Type("wholeMilk", BASICTYPE, 4);
Type* Type::floating = new Type("percentMilk", BASICTYPE, 8);
Type* Type::boolean = new Type("baconOrSausage", BASICTYPE, 1);
Type* Type::function = new Type("breakfastOrder", FUNC, 1);
