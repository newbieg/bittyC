#include <iostream>
#include <string>

#include "error.h"
#include "parser.h"

// this is mainly going to be a render-engine, 
// input a single line of assembly and output 
// the resulting machine-code.
class assembler
{
	public:
	assembler();
	// expected that codeLine is a single command.
	assembler(std::string codeLine);
	std::string assemble();
	std::string getCode();
	// print a list of supported op-codes
	void printOps();

	private:
	std::string assembly;
	std::string output;


};
