#ifndef BITTYC_VARIABLESANDTYPES
#define BITTYC_VARIABLESANDTYPES
// Use this struct to keep track of a variable's 
// place on the stack.

#include <string>
#include <vector>
#include <set>

#include "error.h"

class var
{
	public:
	var();
	var(std::string varName, std::string varType, int address);
	// add a user defined type (like a class, struct, typedef)
	void addAllowedType(std::string newType);
	void setDepth(int deep);
	int getDepth();
	bool isAllowedType(std::string checkType);
	std::string getDeclarator(std::string lineOfCode, int & pos);
	std::string getType();
	void setType(std::string tp);
	int getAddress();
	void setAddress(int val);
	std::string getName();
	bool equal(var other);

	private:
	std::string name;
	std::string type;
	// scope-depth
	int scopeDepth;
	int address;
	static std::set <std::string> allowedTypes;
	error er;
};

// Scope Depth is a grouping of variables, as depth increases new variables
// with the same name can be created as "more local" than
// earlier depths. 
class depth
{
	public:
	depth();
	void addDepth();
	bool addVar(var newVar);
	int getDepth();
	// remove all vars created at current depth
	// and then decrement depth.
	void removeDepth();
	int find(std::string label);


	private:
	int deep;
	std::vector<var> vars;

};





#endif
