#include <string>

#include "parse.h"
#include "error.h"

// takes a parser's tokens and produces assembly output
class compiler
{
	public:
	compiler();

	void load(std::string filePath);
	void compile();
	std::string getCode();


	private:

	parser *Parser;
	error Error;
	
};
