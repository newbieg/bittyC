#ifndef BITTYC_VARIABLESANDTYPES
#define BITTYC_VARIABLESANDTYPES
// Use this struct to keep track of a variable's 
// place on the stack.

#include <string>

class var
{
	public:
	var();
	var(std::string varName, std::string varType);
	std::string name;
	std::string type;
};





#endif
