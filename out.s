.file testCpp/callFunc.cpp
.text
pushq %rbp
movq %rsb, %rbp
.globl timer
	movl $0,(%rbp)
	movl $0, %eax
	popq %rbp
ret
.globl main
	movl $0,-4(%rbp)
	movl $0, %eax
	popq %rbp
ret
