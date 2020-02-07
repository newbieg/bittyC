#include <parse.h>
#include <fstream>
#include <string>
#include <sstream>

#include "error.h"

parser::parser()
{

}

bool parser::loadFile(const char * filePath)
{
	if(filePath[0] != '\0' || filePath == NULL)
	{
		std::ifstream inFile(filePath);
		if(inFile.good())
		{
			std::stringstream ss;
			ss << inFile.rdbuf();
			inFile.close();
		}
		else
		{
			er.setError(BADFILE, filePath, -1);
			return false;
		}
	}
	else
	{
		er.setError(EMPTYFILE, filePath, -1);
	}
	return true;
}

error parser::getError()
{
	return er;
}

std::string next()
{
	return "nope";
}


