# bittyC
An attempt at creating a minimalist C/C++ language compiler that outputs x86_64 Arch Assembly. If succesfull then bittyS and bittyLd should follow to complete the toolchain.

# Note
This is not currently a functional compiler but rather an exercize in futility. I have the current goals:
+ \[1/100\] take commonly used inputs similar to gnu-gcc
+ \[1/2\] Parser that returns tokenized code for compilation
+ \[3/10000\] create a compiler class which
	+ \[1/1000\] builds Assembly from C/C++ code
	+ \[0\] call an Assembler on the resulting .S data file
	+ \[0\] call a linker on the resulting .o object file
	+ \[0\] output an executable file
+ \[\] C/C++ support
	+ \[1/400\] variables
	+ \[0\] structs
	+ \[0\] functions
	+ \[1/300\] type safety
	+ \[0\] classes and objects
+ \[0\] build own Assembler (bittyS)
+ \[0\] build own linker (bittyLd)
+ \[0\] Fully functional toolchain for C and C++ code
+ \[0\] Allow Inline Assembly with asm {} tags to allow for native asm commands. 
+ \[0\] Cross-compilation support for x86_64, ARM, aarch_64, more

This may be a year or more before these goals are even all started on.

