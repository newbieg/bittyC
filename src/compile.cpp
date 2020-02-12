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
	localVarCount = 0;
}


bool compiler::load(std::string filePath)
{
	fileName = filePath;
	return Parser.loadFile(filePath);
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
	std::string head = ".file ";
	head += fileName;
	head += "\n.text\npushq %rbp\nmovq %rsb, %rbp\n";

	assembly = head;

	std::string cCode;
	cCode = Parser.getNext();
	int count = 0;
	while(cCode != "EOF" && count < 1000000)
	{
		// many projects contain more comments than code, 
		// and parser may push even more into the mix.
		// jump to next loop iteration if comment found first
		if(std::string::npos != cCode.find("\\", 0))
		{
			break;
		}
	// Check for int init
		int pos = 0;
		if(matchFind("int", cCode, pos))
		{
			// use vector to keep track of address on stack by index
			vars.push_back(var(nextWord(cCode, pos), "int"));
			std::string val = "0";
			std::cout << "Found an int init\n";
			int valPos = cCode.find("=", pos);
			if(cCode[valPos+1] == '=')
			{
				Error.setError(SYNTAX, fileName + ": " + cCode, Parser.getLine()-1);
			}
			if(valPos != std::string::npos)
			{
				val = nextWord(cCode, valPos);
				std::cout << "Setting a variable to " << val << std::endl;
				// need function to process right-side of equation
			}
			else
			{
				// asign 0 to new variable
				assembly += "movl $0,";
				assembly += toStr((vars.size() - 1) * -4);
				assembly += "(%rbp)\n";
			}
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

	assembly += "popq %rbp\n";
	assembly += "ret\n";
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
