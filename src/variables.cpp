#include <iostream>

#include "variables.h"
#include "utils.h"

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

std::string var::getDeclarator(std::string line, int &pos)
{
	if(line.size() != 0)
	{
		std::string temp = nextWord(line, pos);
		while(!(temp == ""))
		{
			if(isAllowedType(temp))
			{
				return temp;
			}
			pos += temp.length() + 1;
			temp = nextWord(line, pos);
		}
	}
		return (std::string) "";
}

int var::getAddress()
{
	return address;
}

std::string var::getType()
{
	return type;
}

void var::setAddress(int val)
{
	address = val;
}

void var::setType(std::string tp)
{
	if(isAllowedType(tp))
	{
		this->type = tp;
	}
	else
	{
		er.setError(BADVARTYPE, "typeUnknown " + tp, 0);
	}
}

bool var::equal(var other)
{
	return address == other.getAddress();
}



