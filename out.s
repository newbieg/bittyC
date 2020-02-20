.file "callFunc.cpp"
.text

.globl _start
.type _start, @function
_start:
	pushq %rbp
	movq %rsp, %rbp

	movl $0, %eax
	popq %rbp
ret
