#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "parse.h"
#include "error.h"
#include "compile.h"
#include "variables.h"
#include "utils.h"

compiler::compiler()
{
	scopeDepth = 0;
	localVarCount = 0;
}


bool compiler::load(std::string filePath)
{
	fileName = filePath;
	return Parser.loadFile(filePath);
}

// eat away at a math expression
std::string compiler::expression(std::string left, std::string right)
{
	std::string temp = dropWhiteSpace(left);
	std::string command = "";
	int pos = right.find('+', 0);
	if(pos != std::string::npos)
	{
		command = expression(right.substr(0, pos), right.substr(pos+1));
		if(std::string::npos == right.find('+', pos + 1))
		{
			//command += "add r3, " + dropWhiteSpace(right) + ", r3\n";
			command += "add r3, " + nextWord(right, pos) + ", r3\n";
			command += "add r3, " + previousWord(right, pos) + ", r3\n";
		}
		if(temp.size() > 0)
		{
			command += "add r3, " + temp + ", r3\n";
		}
	}
	pos = right.find('-', 0);
	pos = right.find('*', 0);
	pos = right.find('/', 0);

	return command;
}

std::string compiler::openScope()
{
	// leave labels to openFunction(), don't see point in
	// giving each scope a label at this point...
	scopeDepth ++;
	return "pushq %rbp\n" + indent() + "movq %rsp, %rbp\n";
}

std::string compiler::closeScope()
{
	std::string scopeCloser = "";
	scopeCloser += indent() + "popq %rbp\n";
	scopeDepth --;
	if(scopeDepth < 0)
	{
		std::cout << "Scope Depth went negative, scope mismatch in compiler\n";
		scopeDepth = 0;
	}
	return scopeCloser;
}

std::string compiler::openFunction(std::string name)
{
	// at this point we will skip name mangle to be C compliant
	// later we will add when c++ is defined.
	std::string ret = indent() + ".globl " + name + '\n';
	ret += indent() + ".type " + name + ", @function\n";
	ret += indent() + name + ":\n";
	ret += indent() + openScope();
	return ret;
}

// need to figure out the whole return a type calue deal...
std::string compiler::closeFunction(std::string retLine)
{
	std::string returnString;
	int pos = 0;
	std::string retVal = "$0";
	if(matchFind("return", retLine, pos))
	{
		pos += 6;
		retVal = nextWord(retLine, pos);
		int posEnd = retLine.find(";");
		if(posEnd == std::string::npos)
		{
			Error.setError(SYNTAX, retLine, 0);
		}
		else
		{
			retVal = retVal.substr(0, retVal.find(';'));
			if(retVal.empty())
			{
				retVal = "$0";
			}
			if(isLabel(retVal))
			{
				// is either a var or function
				// if funct then call before return
				// if var then mov
/*				if(vars.isInVars(retVal))
				{
					// Now time to replace vec vars
					// with the new container (depth)
					//
					// find the first matching var
					// in the vars vec and we then
					// set retVal to the address on 
					// the stack so it can be moved 
					// to %eax...
				}
*/
			}
			std::cout << "RETURN VAL: " << retVal << "\n";
		}

	}

	if(retVal.size() >= 1)
	{
		 returnString += indent() + "movl " + retVal + ", %eax\n";

	}
	return indent() + closeScope() + "ret\n";
}

std::string compiler::indent()
{
	std::string tabs = "";
	for(int i = 0; i < scopeDepth; i ++)
	{
		tabs += "\t";
	}
	return tabs;
}

/* void compiler::compile()
 * This has a lot of different options. My current version just slams into
 * the line and hopes to find something interesting that it can use. This
 * is not the right approach since it assumes correct syntax (bad code will not fail, just produce bad code).
 * A better solution would be to go letter by letter through the line and detect commands
 * that way. Or to use a stringstream and get word-by-word, though that also causes issues
 * since whitespace is supposed to be ignored between many syntax commands (2+var == var + 2)
 */

void compiler::compile()
{
	var voidType;
	voidType.addAllowedType("void");
	voidType.addAllowedType("int");
	voidType.addAllowedType("double");
	voidType.addAllowedType("float");
	voidType.addAllowedType("long");
	voidType.addAllowedType("short");
	voidType.addAllowedType("char");
	std::string head = ".file \"";
	head += fileName;
	head += "\"\n.text\n";

	assembly = head;

	std::string cCode;
	cCode = Parser.getNext();
	int count = 0;
	while(cCode != "EOF" && count < 1000000)
	{
		// many projects contain more comments than code, 
		// and parser may push even more into the mix.
		// jump to next loop iteration if comment found first
		if(std::string::npos != cCode.find("//", 0))
		{
			std::string comment = cCode.substr(cCode.find("//"));
			cCode = cCode.substr(0, comment.length());
			assembly += comment + '\n';
			std::cout << "// Found a line comment\n";
			
		}
	// Check for int init
		int pos = 0;
		//if(matchFind("int", cCode, pos).) // side-tracked.
		std::string declarator = voidType.getDeclarator(cCode, pos);
		std::cout << '(' << cCode << ')';
		if(!(declarator.empty()))
		{
			// check if a function declarative or definitive;
			pos += declarator.length();
			std::string  name = nextWord(cCode, pos);
			std::cout << '-' << name << ":";
			int isFunction = name.find("(");
			if(isFunction != std::string::npos)
			{
				name = name.substr(0, name.find("("));
				std::cout << declarator << " returning Function found!\n";
				
				// check if function definition
				if(cCode.find("{") != std::string::npos)
				{
					
					std::cout << name << ":    above has definition\n";
					std::string functNameCall = openFunction(name);
					std::cout << functNameCall << std::endl;
					assembly += functNameCall + '\n';
				}
				//continue;
			}

			// wasn't a function, so it is a variable? 
			std::string val = "0";
			std::cout << "Found an " << declarator << " init\n";
			int valPos = cCode.find("=", pos);
			if(cCode[valPos+1] == '=')
			{
				// int dec has "=="
				Error.setError(SYNTAX, fileName + ": " + cCode, Parser.getLine()-1);
				return;
			}
			if(valPos != std::string::npos)
			{
				val = nextWord(cCode, valPos);
				std::cout << "Setting a variable to " << val << std::endl;
				vars.push_back(var(nextWord(cCode, pos), declarator, 0));
				assembly += "//Need to work on var definition next\n";
				// need function to process right-side of equation
				// see expression();
			}
			else
			{
				// asign 0 to new variable
				int addr = (1 + vars.size()) * -4;
				assembly += indent() + "movl $0, ";
				assembly += toStr(addr);
				assembly += "(%rbp)\n";
				vars.push_back(var(nextWord(cCode, pos), declarator, addr));
			}
		}
		pos = 0;
		if(matchFind("if", cCode, pos))
		{
			// need to figure out a scope mechanism first
			// including accessing the nearest nested variables.
			// come back here after variables are tracked and
			// scoped correctly.
			//
			// order of operations return if()? 
			// if(){return val}
			// return val==3?val:other
		}
		pos = 0;
		if(matchFind("return", cCode, pos))
		{
			assembly += closeFunction(cCode);
		}
		/*
		pos = cCode.find('+', 0);
		if(pos != std::string::npos)
		{
			std::string first = previousWord(cCode, pos);
			std::string second = nextWord(cCode, pos);
			bool isIntF = false;
			bool isIntS = false;
			int f, s;
			// need to determine if first is a known variable, or an actual number
			if(isDecimal(first[0]))
			{
				isIntF = true;
				f = toInt(first.c_str());
			}
			else
			{
				// add new variable "first" on the stack at localVarCount * -1;
				localVarCount ++;
				assembly += "movl Wait, This is a work in progress, I have to get ready for work, so I need to stop here." ; 
			}

			if(isDecimal(second[0]))
			{
				isIntS = true;
				s = toInt(second.c_str());
			}
			else
			{
				// add new variable "first" on the stack at localVarCount * -1;
				localVarCount ++;
				assembly += "movl "; 
			}
		}
		*/
		int isVoidInput = cCode.find("()", 0);
		int additionPos = std::string::npos != cCode.find("+", 0);
		int intDecl= cCode.find("int", 0);

		count ++;
		cCode = Parser.getNext();
	}

}

bool compiler::write(std::string outFilePath)
{
	std::ofstream ofile(outFilePath.c_str());
	if(ofile.good())
	{
		ofile << assembly;
		return true;
	}
	else
	{
		Error.setError(BADOUTFILE, outFilePath, 0);
	}
	return false;
}

error compiler::getError()
{
	return Error;
}


	/*
	private:

	parser *Parser;
	error Error;
	*/
