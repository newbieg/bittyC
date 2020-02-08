
#ifndef BITTYC_ERROR
#define BITTYC_ERROR

#include <string>
enum err
{
	SYNTAX, 
	BADFILE,
	NOTCODE,
	EMPTYFILE,
	UNKNOWN,
	ERRMAX
};


class error
{
	public:
	error();
	std::string toString();
	void setError(err errName, std::string, int line);
	


	private:
	int errorNum;
	int line;
	std::string fileName;
	std::string errorName;
	std::string errorDesc;
	bool hasError;

};

#endif
