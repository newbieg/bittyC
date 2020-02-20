.file testCpp/callFunc.cpp
.text
pushq %rbp
movq %rsb, %rbp
.globl timer
.type timer, @function
timer:
	pushq %rbp
	movq %rsp, %rbp

	movl $0,-4(%rbp)
\Need to work on var definition next
\Need to work on var definition next
\Need to work on var definition next
	movl $0, %eax
	popq %rbp
ret
.globl main
.type main, @function
main:
	pushq %rbp
	movq %rsp, %rbp

	movl $0,-20(%rbp)
	movl $0, %eax
	popq %rbp
ret
