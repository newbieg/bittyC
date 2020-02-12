.file test.cpp
.text
pushq %rbp
movq %rsb, %rbp
movl $0,-4(%rbp)
movl $0,-20(%rbp)
popq %rbp
ret
