/* simple utility functions that may be required often during parsing
 */
#include <string>
#include <cstring>

char toUpper(char chr)
{
	if(chr >= 'a' && chr <= 'z')
	{
		return chr + 'A' - 'a';
	}
	return chr;
}

bool isDecimal(char chr)
{
	if(chr >= '0' && chr <= '9')
	{
		return true;
	}
	return false;
}

bool isAlpha(char chr)
{
	char tmp = toUpper(chr);
	if(tmp >= 'A' && tmp <= 'Z')
	{
		return true;
	}
	return false; 
}

int toInt(char *number)
{
	int output = 0;
	int start = 0;
	bool isNegative = (number[0] == '-');
	if(isNegative)
	{
		start ++;
	}
	for(int i = start; i < strlen(number) && isDecimal(number[i]); i ++)
	{
		output *= 10;
		output += number[i] - '0';
	}
	if(isNegative)
	{
		output *= -1;
	}
	return output;
}

std::string reverse(std::string str)
{
	std::string output;
	for(int i = str.length() - 1; i >= 0; i --)
	{
		output += str[i];

	}
	return output;
}


std::string toStr(int number)
{
	std::string output = "";
	std::string revd = "";
	bool isNegative = (number < 0);
	int start = 0;
	if(isNegative)
	{
		number *= -1;
		output += "-";
		start ++;
	}

	while(number > 0)
	{
		revd += (number % 10) + '0';
		number -= number % 10;
		number = number / 10;
	}
	output += reverse(revd);
	
	
	return output;
}



std::string dropLeadWhiteSpace(std::string text, int start)
{
	for(int i = start; i < text.length(); i ++)
	{
		if(text[i] == ' '){}
		else if(text[i] == '\t'){}
		else
		{
			start = i;
			break;
		}
	}
	return text.substr(start);
}






