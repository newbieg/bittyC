# bittyC
An attempt at creating a minimalist C/C++ language compiler that outputs x86_64 Arch Assembly. If succesfull then bittyS and bittyLd should follow to complete the toolchain.

# Note
I am following a tutorial. This is not currently a functional compiler. I have the current goals:
+\[\] take commonly used inputs similar to gnu-gcc
+\[\] create a compiler class which takes code files as input
	+\[\] Read files
	+\[\] build Assembly from that code
	+\[\] call an Assembler on the resulting .S data file
	+\[\] call a linker on the resulting .o object file
	+\[\] output an executable file
+\[\] build own Assembler (bittyS)
+\[\] build own linker (bittyLd)
+\[\] Fully functional toolchain for C and C++ code

This may be a year or more before these goals are even all started on.

