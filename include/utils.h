/* simple utility functions that may be required often during parsing
 */

#ifndef MYBITTYCUTILITIES
#define MYBITTYCUTILITIES
#include <string>

char toUpper(char chr);
bool isDecimal(char chr);
bool isAlpha(char chr);
// check if the given varOrFunction is a viable name,
// not containing arithmetic, and not a const number;
bool isLabel(std::string varOrFunction);
// check if the given number is just that.
bool isConst(std::string number);
// look for exact match of a word in a codeLine, 
// return true if found, 
// set pos to first letter if found, std::string::npos if not
bool matchFind(std::string word, std::string codeLine, int &pos);
int toInt(const char *number);
std::string reverse(std::string str);
std::string toStr(int number);
// given text starts with whiteSpace and contains commands and further whiteSpace, 
// drop the initial whitespace up until the first command.
std::string previousWord(std::string text, int &start);
std::string nextWord(std::string text, int &start);
std::string dropWhiteSpace(std::string input);

// returns true if first is to the left of second in the codeLine
// returns false if first is to the right, or if either first or second are not found in codeLine
bool isLeftOf(std::string first, std::string second, std::string codeLine); 
#endif
