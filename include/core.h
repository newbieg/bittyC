#ifndef COREVERION
#define COREVERSION "0.00.01"
// Check if we need to produce 64 bit assembly
# if defined(_WIN64) || defined(__x86_64__) || defined(_M_X64)
	#define BIT64 
# endif

#endif

