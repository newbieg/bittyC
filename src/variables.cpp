#include "variables.h"

var::var()
{
	// void type or leave as empty?
	allowedTypes = "int char float double bool void  long long short const";
}

var::var(std::string varName, std::string varType)
{
	name = varName;
	type = varType;
}
