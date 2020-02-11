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

void compiler::compile()
{
	std::string head = ".file ";
	head += fileName;
	head += "\n.text\n";

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
		int pos = cCode.find('+', 0);
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
