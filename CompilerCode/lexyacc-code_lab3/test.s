
.data
formatString:
	.string	"Number :%d "
vars:
	.zero	2048
isInReg:
	.zero	2048

.text
.global	main		
    
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	pushq	$1000000
	popq	%r12
	pushq	$100000000
	popq	%r13
	pushq	$0
	popq	%r14
L000:
	movq	%r12, %rbx
	pushq	%rbx
	pushq	$0
	popq	%rsi
	popq	%rdi
	cmpq	%rsi, %rdi
	jle	L001
	movq	%r14, %rbx
	pushq	%rbx
	movq	%r13, %rbx
	pushq	%rbx
	movq	%r12, %rbx
	pushq	%rbx
	movq	$0, %rdx
	popq	%rsi
	popq	%rax
	divq	%rsi
	pushq	%rax
	popq	%rsi
	popq	%rdi
	addq	%rsi, %rdi
	pushq	%rdi
	popq	%r14
	movq	%r12, %rbx
	pushq	%rbx
	pushq	$1
	popq	%rsi
	popq	%rdi
	subq	%rsi, %rdi
	pushq	%rdi
	popq	%r12
	movq	%r12, vars+880(%rip)
	movq	vars+880(%rip), %r12
	movq	%r13, vars+920(%rip)
	movq	vars+920(%rip), %r13
	movq	%r14, vars+776(%rip)
	movq	vars+776(%rip), %r14
	jmp	L000
L001:
	movq	%r14, %rbx
	pushq	%rbx
	movq	%r13, %rbx
	pushq	%rbx
	pushq	$1000
	movq	$0, %rdx
	popq	%rsi
	popq	%rax
	divq	%rsi
	pushq	%rax
	movq	$0, %rdx
	popq	%rsi
	popq	%rax
	divq	%rsi
	pushq	%rax
	movl	$formatString, %edi
	popq	%rsi
	xor	%rax, %rax
	call	printf
	leave
	ret

