#include "test.h"

int scope()
{
	// this is a line comment.
	static int real = 1+4;//this comment is at the end of code
	int another;/* this
	 * is a block
	 * of comments.
	 */
	return hello;
}

void scoper(){
	int real = 1032+4;
	int another = real + 9;
}


int main()
{
	scope();
	scoper();
	return 123411;
}
