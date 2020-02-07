#ifndef BITTYCPARSER_ZERO
#define BITTYCPARSER_ZERO

#include "error.h"
#include <string>

class parser
{
	public:
	parser();
	bool loadFile(const char * filePath);
	std::string getNext();
	error getError();

	private:
	std::string code;
	std::string fileName;
	error er;
	
};


#endif
