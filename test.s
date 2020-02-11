	.file	"test.cpp"
	.text
	.data
	.align 4
	.type	_ZZ5scopevE4real, @object
	.size	_ZZ5scopevE4real, 4
_ZZ5scopevE4real:
	.long	5
	.text
	.globl	_Z5scopev
	.type	_Z5scopev, @function
_Z5scopev:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	_Z5scopev, .-_Z5scopev
	.globl	_Z6scoperv
	.type	_Z6scoperv, @function
_Z6scoperv:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$5, -4(%rbp)
	movl	-4(%rbp), %eax
	addl	$9, %eax
	movl	%eax, -8(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	_Z6scoperv, .-_Z6scoperv
	.ident	"GCC: (GNU) 9.2.1 20190827 (Red Hat 9.2.1-1)"
	.section	.note.GNU-stack,"",@progbits
