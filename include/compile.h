#include <string>
#include <vector>

#include "parse.h"
#include "error.h"
#include "variables.h"

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
	bool write(std::string outputFilePath);

	// commands
	// std::string negate(std::string num);
	std::string add(std::string left, std::string right);
	std::string subract(std::string left, std::string right);
	std::string assign(std::string left, std::string right);
	std::string multiply(std::string left, std::string right);
	std::string divide(std::string left, std::string right);

	std::string expression(std::string left, std::string right);



	private:

	parser Parser;
	error Error;
	std::string fileName;
	std::string assembly;
	int localVarCount;
	std::vector <var> vars;
	
};
