#include <fstream>
#include <iostream>
#include <string.h>
#include <string>

#include "core.h"
#include "utils.h"
#include "parse.h"
#include "compile.h"

// This is a compiler that reads some cpp file and outputs x86_64 assembly
// It would be nice to bootrap it to itself, so limiting the included libraries
// might be a good idea...


void help()
{
	std::cout << "Help: I need all possible arguments to make sense.\n";
}

int main(int argc, char ** argv)
{
	
	std::string filePath;
	// get the command line args
	// Will attempt to mimic Gnu-Gcc inputs so Makefiles can be easilly modified
	for(int i = 1; i < argc; i ++)
	{
		if(!strcmp(argv[i], "help"))
		{
			help();
		}
		else if(!strcmp(argv[i], "-I"))
		{
			// include folder as a source of header files.
			
		}
		else if(!strcmp(argv[i], "-o"))
		{
			// set output fileName
		}
		else if(!strcmp(argv[i], "-Wall"))
		{
			//enable base warnings
		}
		else if(!strcmp(argv[i], "-E"))
		{
			// build preprocessor output only,
			// send to stdout
		}
		else if(!strcmp(argv[i], "-S"))
		{
			// build Assembly output (Currently the default)
		}
		else if(!strcmp(argv[i], "-C"))
		{
			// Produce pure machine code without linking
			// use for making libraries?
		}
		else if(!strcmp(argv[i], "-save-temps"))
		{
			// save all intermediate files (preprocessed, assembled, object)
		}
		else if(!strcmp(argv[i], "-l"))
		{
			// lowercase L, link to shared libs
		}
		else if(!strcmp(argv[i], "-fPIC"))
		{
			// Produce position independent code, best for obj files 
			// that are intended to be shared libs
		}
		else if(!strcmp(argv[i], "-V"))
		{
			// verbose output while compiling
		}
		else if(!strcmp(argv[i], "--version"))
		{
			// send version to stdout and exit without further processing
			// std::cout << compilerName << " " << compilerVersion << '\n' << compilerDescription << '\n';
			std::cout << "Version: "<< COREVERSION << std::endl;
			exit(0);
		}
		else
		{
			// include argv[i] as filePath to code 
			// issue error if not a *.cpp or *.h file
			filePath = argv[i];

		}
	}
	compiler c;
	parser p;
	c.load(filePath.c_str());
	p.loadFile(filePath.c_str());
	std::string temp;
	
	while(temp != "EOF")
	{
		temp = p.getNext();
		std::cout << temp << "\n";
	}

	c.compile();

	std::cout << c.getError().toString() << std::endl;

}
