/* simple utility functions that may be required often during parsing
 */

#ifndef MYBITTYCUTILITIES
#define MYBITTYCUTILITIES
#include <string>

char toUpper(char chr);
bool isDecimal(char chr);
bool isAlpha(char chr);
int toInt(char *number);
std::string reverse(std::string str);
std::string toStr(int number);
// given text starts with whiteSpace and contains commands and further whiteSpace, 
// drop the initial whitespace up until the first command.
std::string dropLeadWhiteSpace(std::string text);
#endif
