.file test.cpp
.text
pushq %rbp
movq %rsb, %rbp
movl $0,-4(%rbp)
movl $0,-20(%rbp)
movl $123411;, %eax
ret
popq %rbp
ret
