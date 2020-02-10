#include <string>

#include "parse.h"
#include "error.h"

// takes a parser's tokens and produces assembly output
class compiler
{
	public:
	compiler();

	bool load(std::string filePath);
	void compile();
	std::string getCode();

	error getError();
	void setError(err, std::string filePath, int line);


	private:

	parser Parser;
	error Error;
	std::string fileName;
	
};
