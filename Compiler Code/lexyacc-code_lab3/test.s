
.globl	vars
	.align 32
	.type	vars, @object
	.size	vars, 2048
vars:
	.zero	2048
	.section	.rodata
.LC0:
	.text
	.globl	main
	.type	main, @function
    .zero 2048
    
main:
	pushq	$732
	popq	%rax
	pushq	$2684
	popq	%rcx
L000:
	cmpq %rcx, %rax
	je	L001
	cmpq %rcx, %rax
	jl	L002
	subq	%rcx, %rax
	pushq	%rax
	popq	%rax
	jmp	L003
L002:
	subq	%rax, %rcx
	pushq	%rcx
	popq	%rcx
L003:
	jmp	L000
L001:
	print
	gcd
	print
