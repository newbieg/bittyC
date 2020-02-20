#ifndef BITTYC_VARIABLESANDTYPES
#define BITTYC_VARIABLESANDTYPES
// Use this struct to keep track of a variable's 
// place on the stack.

#include <string>
#include <set>

#include "error.h"

class var
{
	public:
	var();
	var(std::string varName, std::string varType, int address);
	// add a user defined type (like a class, struct, typedef)
	void addAllowedType(std::string newType);
	bool isAllowedType(std::string checkType);
	int getAddress();
	void setAddress(int val);
	bool equal(var other);


	private:
	std::string name;
	std::string type;
	int address;
	static std::set <std::string> allowedTypes;
	error er;
};





#endif
