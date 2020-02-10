#include <parse.h>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

#include "error.h"
#include "utils.h"



parser::parser()
{
	cursor = 0;
	commonSyntax = "\"\'\\!.?<>,_:;%=[]-+*&|";
	blockComment = false;
	showLines = true;
}

bool parser::isCommonSyntax(char chr)
{
	if(std::string::npos == commonSyntax.find(chr, 0))
	{
		return true;
	}
	return false;
}

int parser::getLine()
{
	return line;
}

bool parser::loadFile(std::string filePath)
{
	fileName = filePath;
	line = 0;
	if(filePath[0] != '\0')
	{
		if(filePath.substr(filePath.length() - 4) != ".cpp" && filePath.substr(filePath.length() - 2) != ".h")
		{
			er.setError(NOTCODE, filePath, -1);
			return false;
		}
		std::ifstream inFile(filePath.c_str());
		if(inFile.good())
		{
			std::stringstream ss;
			ss << inFile.rdbuf();
			inFile.close();
			code = ss.str();
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
	line = 1;
	return true;
}

error parser::getError()
{
	return er;
}

std::string parser::getNext()
{
	std::string temp;
	bool startGet = true;
	if(cursor < code.length())
	{
		bool lineComment = false;
		bool getMore = true;
		while(getMore)
		{
			if(startGet)
			{
				if(showLines)
				{
					temp = toStr(line);
				}
				if(blockComment)
				{
					 temp += "//";
				}
			}
			startGet = false;
			if(code[cursor] == '/')
			{
				if(code[cursor+1] == '*')
				{
					getMore = false;
					blockComment = true;
					cursor += 3;
					continue;
				}
				else if(code[cursor+1] == '/')
				{
					lineComment = true;
				}
			}
			else if(code[cursor] == '*')
			{
				if(code[cursor+1] == '/')
				{
					blockComment = false;
					cursor += 2;
					getMore = false;
					break;
				}
			}
			if(isAlpha(code[cursor]) || isDecimal(code[cursor]))
			{
				temp += code[cursor];
			}
			else if(code[cursor] == '\n')
			{
				line ++;
				temp += ' ';
				if(lineComment)
				{
					getMore = false;
					break;
				}
				if(blockComment)
				{
					getMore = false;
				}
			}
			else if(code[cursor] == '+')
			{
				temp += '+';
			}
			else if(code[cursor] == '=')
			{
				temp += '=';
			}
			else if(code[cursor] == '\t')
			{
				// do nothing	
			}
			else if(code[cursor] == ' ')
			{
				temp += ' ';
			}
			else if(code[cursor] == '(')
			{
				temp += '(';
			}
			else if(code[cursor] == ')')
			{
				temp += ')';
			}
			else if(code[cursor] == '{')
			{
				temp += '{';
				getMore = false;
			}
			else if(code[cursor] == '}')
			{
				temp += '}';
				if(code[cursor+1] == ';')
				{
					temp += ';';
					cursor ++;
				}
				getMore = false;
	
			}
			else if(isCommonSyntax(code[cursor]))
			{
				temp += code[cursor];
			}
			else if(code[cursor] == ';')
			{
				temp += ';';
				getMore = false;
			}
			else
			{
				er.setError(SYNTAX, fileName, line);
				getMore = false;
			}


			cursor ++;
			if(cursor > code.length())
			{
				getMore = false;
			}

		}
		return temp;
	}
	return "EOF";
}


