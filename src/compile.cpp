#include <string>

#include "parse.h"
#include "error.h"
#include "compile.h"

compiler::compiler()
{

}

bool compiler::load(std::string filePath)
{
	return Parser.loadFile(filePath);
}

void compiler::compile()
{
	
	
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
