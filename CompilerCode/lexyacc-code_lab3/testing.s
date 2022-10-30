	.file	"testing.c"
	.text
	.globl	array
	.bss
	.align 32
	.type	array, @object
	.size	array, 1024
array:
	.zero	1024
	.section	.rodata
.LC0:
	.string	"%d\n"
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
	subq	$32, %rsp
	movl	$1000001, -4(%rbp)
	movl	$100000000, -20(%rbp)
	movl	$0, -8(%rbp)
	movl	$0, -12(%rbp)
	movl	$0, -16(%rbp)
	jmp	.L2
.L5:
	cmpl	$0, -16(%rbp)
	jne	.L3
	movl	-4(%rbp), %eax
	movl	%eax, -12(%rbp)
	movl	$1, -16(%rbp)
	jmp	.L4
.L3:
	movl	-4(%rbp), %eax
	negl	%eax
	movl	%eax, -12(%rbp)
	movl	$0, -16(%rbp)
.L4:
	movl	-20(%rbp), %eax
	cltd
	idivl	-12(%rbp)
	addl	%eax, -8(%rbp)
	subl	$2, -4(%rbp)
.L2:
	cmpl	$0, -4(%rbp)
	jg	.L5
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	imulq	$351843721, %rdx, %rdx
	shrq	$32, %rdx
	sarl	$13, %edx
	sarl	$31, %eax
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	-8(%rbp), %eax
	cltd
	idivl	%ecx
	sall	$2, %eax
	movl	%eax, %esi
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
