#include "error.h"
#include <string>


error::error()
{
	errorNum = ERRMAX;
	errorDesc = "No Errors detected\n";
	errorName = "None: ";
}

std::string error::getError()
{
	return errorName + errorDesc;
}






