#include <string>
enum err
{
	SYNTAX, 
	UNKNOWN,
	ERRMAX
};


class error
{
	public:
	error();
	std::string getError();
	void setError(int err);


	private:
	int errorNum;
	std::string errorName[ERRMAX];
	std::string errorDesc[ERRMAX];

};



