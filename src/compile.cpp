#include <string>
#include <iostream>

#include "parse.h"
#include "error.h"
#include "compile.h"

compiler::compiler()
{

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
	head += "\n.text";

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
		std::cout << cCode << std::endl;
		int parenthPos = cCode.find("(", 0);

		int isVoidInput = cCode.find("()", 0);
		int additionPos = std::string::npos != cCode.find("+", 0);
		int intDecl= cCode.find("int", 0);

		count ++;
		cCode = Parser.getNext();


	}
	

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
