#ifndef BITTYCPARSER_ZERO
#define BITTYCPARSER_ZERO

#include "error.h"
#include <string>

// parse a file and retrieve code in string tokens that equate to
// a whole command such as
// int var = foo;
// if((bool)){ 
// while((bool)){
// functionCall();
// }
//
// Drops white space, but keeps comments so they can remain in 
// the assembly file.
class parser
{
	public:
	parser();
	bool loadFile(std::string filePath);
	std::string getNext();
	error getError();
	bool isCommonSyntax(char chr);
	int getLine();

	private:
	std::string code;
	std::string fileName;
	int line;
	std::string commonSyntax;
	error er;
	std::string tokens;
	int cursor;
	bool blockComment;
	bool showLines;
	
};


#endif
