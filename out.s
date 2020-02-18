.file testCpp/callFunc.cpp
.text
pushq %rbp
movq %rsb, %rbp
.globl timer
movl $0,(%rbp)
movl $7;, %eax
ret
.globl main
movl $0,-4(%rbp)
movl $0;, %eax
ret
popq %rbp
ret
