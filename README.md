# bittyC
An attempt at creating a minimalist C/C++ language compiler that outputs x86_64 Arch Assembly. If succesfull then bittyS and bittyLd should follow to complete the toolchain.

# Note
I am following a tutorial. This is not currently a functional compiler. I have the current goals:
+ \[1/10\] take commonly used inputs similar to gnu-gcc
+ \[1/3\] Parser that returns tokenized code for compilation
+ \[1/1000\] create a compiler class which
	+ \[\] builds Assembly from C/C++ code
	+ \[\] call an Assembler on the resulting .S data file
	+ \[\] call a linker on the resulting .o object file
	+ \[\] output an executable file
+ \[\] C/C++ support
	+ \[\] variables
	+ \[\] structs
	+ \[\] functions
	+ \[\] type safety
	+ \[\] classes and objects
+ \[\] build own Assembler (bittyS)
+ \[\] build own linker (bittyLd)
+ \[\] Fully functional toolchain for C and C++ code
+ \[\] Allow Inline Assembly with asm {} tags to allow for native asm commands. 
+ \[\] Cross-compilation support for x86_64, ARM, aarch_64, more

This may be a year or more before these goals are even all started on.

