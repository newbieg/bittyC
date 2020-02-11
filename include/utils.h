/* simple utility functions that may be required often during parsing
 */

#ifndef MYBITTYCUTILITIES
#define MYBITTYCUTILITIES
#include <string>

char toUpper(char chr);
bool isDecimal(char chr);
bool isAlpha(char chr);
bool matchFind(std::string word, std::string codeLine);
int toInt(const char *number);
std::string reverse(std::string str);
std::string toStr(int number);
// given text starts with whiteSpace and contains commands and further whiteSpace, 
// drop the initial whitespace up until the first command.
std::string previousWord(std::string text, int start);
std::string nextWord(std::string text, int start);
#endif
