#include "variables.h"

var::var()
{
	// void type or leave as empty?
}

var::var(std::string varName, std::string varType)
{
	name = varName;
	type = varType;
}
