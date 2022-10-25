	.file	"testing.c"
	.text
	.globl	array
	.bss
	.align 32
	.type	array, @object
	.size	array, 2048
array:
	.zero	2048
	.section	.rodata
.LC0:
	.string	"A is :%d"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	$1, array+8(%rip)
	movq	array+8(%rip), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 11.3.1 20220421 (Red Hat 11.3.1-3)"
	.section	.note.GNU-stack,"",@progbits
