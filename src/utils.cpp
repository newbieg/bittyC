/* simple utility functions that may be required often during parsing
 */
#include <string>
#include <cstring>
#include <iostream>

#include "utils.h"

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

bool isLabel(std::string label)
{
	if(!(isAlpha(label[0]) || label[0] == '_'))
	{
		return false;
	}
	for(int i = 1; i < label.length(); i ++)
	{
		if(!(isAlpha(label[i]) || isDecimal(label[i])))
		{
			return false;
		}
	}
	return true;
}

bool isConst(std::string number)
{
	bool onePeriod = false;
	for(int i = 0; i < number.length(); i ++)
	{
		if(!(isDecimal(number[i])))
		{
			if(!onePeriod)
			{
				if(number[i] == '.')
				{
					onePeriod = true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
	}
	return true;
}

bool matchFind(std::string word, std::string lineCode, int & pos)
{
	pos = lineCode.find(word, pos);
	if(pos != std::string::npos)
	{
		if(pos + word.length() + 1 < lineCode.length())
		{
			char after = lineCode[pos+word.length()];
			if(isAlpha(after) || isDecimal(after))
			{
				return false;
			}
		}
		if(pos > 0)
		{
			char before = lineCode[pos - 1];
			if(isAlpha(before) || isDecimal(before))
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

int toInt(const char *number)
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


std::string previousWord(std::string text, int start)
{
	std::string ret = "";
	start --;
	for(int i = start; (text[i] == ' ' || text[i] == '\t') && start > 0; i --)
	{
		start = i - 1;
	}

	for(int i = start; (text[i] != ' ' && text[i] != '\t') && i > 0; i --)
	{
		ret += text[i];
	}
	ret = reverse(ret);
	return ret;
	
}

std::string nextWord(std::string text, int start)
{
	std::string ret = "";
	start ++;
	int len = text.length();
	for(int i = start; (text[i] == ' ' || text[i] == '\t') && start < len; i ++)
	{
		start = i + 1;
	}

	for(int i = start; (text[i] != ' ' && text[i] != '\t') && i < len; i ++)
	{
		ret += text[i];
	}
	return ret;
	
}

std::string dropWhiteSpace(std::string input)
{
	std::string temp = "";
	for(int i = 0; i < input.length(); i ++)
	{
		if(input[i] != ' ' && input[i] != '\t')
		{
			temp += input[i];
		}
	}
	return temp;
}

bool isLeftOf(std::string first, std::string second, std::string codeLine)
{

	int firstPos, secondPos;
	matchFind(first, codeLine,firstPos);
	matchFind(second, codeLine, secondPos);
	if(firstPos == std::string::npos || secondPos == std::string::npos)
	{
		return false;
	}
	return firstPos < secondPos;
}
