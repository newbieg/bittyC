#include "variables.h"

std::set<std::string> var::allowedTypes;

var::var()
{
	// void type or leave as empty?
	// std::string types = "int char float double bool void  long long short const";
	// Leave the definition/addition of allowed types completely to the compiler. 
	// compiler will have to create an empty var first, good practice: call it void
	// compiler then gives list of allowed var types.
}

var::var(std::string varName, std::string varType, int addr)
{
	name = varName;
	type = varType;
	address = addr;
}

void var::addAllowedType(std::string newType)
{
	// might eventually add return of whether the
	// returned pair indicates that the newType actually
	// already existed. 
	allowedTypes.emplace(newType);
}


bool var::isAllowedType(std::string checkType)
{
	return allowedTypes.find(checkType) != allowedTypes.end();
	
}
int var::getAddress()
{
	return address;
}

void var::setAddress(int val)
{
	address = val;
}

bool var::equal(var other)
{
	return address == other.getAddress();
}



