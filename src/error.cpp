#include "error.h"
#include <string>
#include <utils.h>


error::error()
{
	errorNum = ERRMAX;
	errorDesc = "No Errors detected\n";
	errorName = "None: ";
	hasError = false;
}

std::string error::toString()
{
	if(line > 0)
	{
		return errorName + errorDesc;
	}
	return errorName + errorDesc + toStr(line);
}

void error::setError(err errName, std::string filePath, int line)
{
	errorNum = errName;
	switch(errName)
	{
		case SYNTAX:
			errorDesc = filePath;
			errorDesc += "- Syntax error found on line ";
			errorDesc += toStr(line);
			errorName = "Syntax: ";
			hasError = true;
		break;
		case BADFILE:
			errorDesc = "Could not load file ";
			errorDesc += filePath;
			errorName = "Bad File Input: ";
			hasError = true;
		break;
		case BADOUTFILE:
			errorDesc = "Could not write to file, check file permissions and paths: ";
			errorDesc += filePath;
			errorName = "Bad File Output: ";
			hasError = true;
		break;
		case NOTCODE:
			errorDesc = "Parser was asked to load a file not ending in .cpp or .h: ";
			errorDesc += filePath;
			errorName = "Bad File Input: ";
			hasError = true;
		break;
		case BADVARTYPE:
			errorDesc = "Variable type is not viable: ";
			errorDesc += filePath;
			errorDesc += toStr(line);
			errorName = "Invalid variable type";
			hasError = true;
		break;
		case EMPTYFILE:
			errorDesc = "Parser was asked to load an empty file ";
			errorDesc += filePath;
			errorName = "Bad File Input: ";
			hasError = true;
		break;

		default:
			errorDesc = "No Errors detected";
			errorName = "None: ";
			hasError = false;
		break;
	}
}


err error::getError()
{
	return errorNum;
}




