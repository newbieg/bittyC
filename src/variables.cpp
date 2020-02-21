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

void var::setDepth(int deep)
{
	scopeDepth = deep;
}

int var::getDepth()
{
	return scopeDepth;
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

std::string var::getName()
{
	return name;
}

bool var::equal(var other)
{
	return address == other.getAddress();
}



depth::depth()
{
	deep = 0;
}

void depth::addDepth()
{
	deep ++;
}

bool depth::addVar(var push)
{
	// only add var if it's name does not
	// exist in the current depth...
	for(int i = 0; i > 0 && vars[i].getDepth() == deep; i --)
	{
		if(push.getName() == vars[i].getName())
		{
			return false;
		}
	}
	vars.push_back(push);
	return true;
}

int depth::getDepth()
{
	return deep;
}

void depth::removeDepth()
{
	for(int i = vars.size(); i > 0; i --)
	{
		if(vars[i].getDepth() == deep)
		{
			vars.pop_back();
		}
		else
		{
			deep --;
			return;
		}
	}
}

int depth::find(std::string label)
{
	for(int i = vars.size(); i > 0; i ++)
	{
		if(vars[i].getName() == label)
		{
			return i;
		}
	}
	return -1;
}





