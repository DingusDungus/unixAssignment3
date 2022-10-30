
.data
formatString:
	.string	"Number :%d\n "
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
	pushq	$1000001
	popq	%r12
	movq	%r12, vars+880(%rip)
	pushq	$100000000
	popq	%r13
	movq	%r13, vars+920(%rip)
	pushq	$0
	popq	%r14
	movq	%r14, vars+776(%rip)
	pushq	$0
	popq	%r15
	movq	%r15, vars+928(%rip)
L000:
	movq	%r12, %rbx
	pushq	%rbx
	pushq	$0
	popq	%rsi
	popq	%rdi
	cmpq	%rsi, %rdi
	jle	L001
	movq	vars+880(%rip), %r12
	movq	vars+920(%rip), %r13
	movq	vars+776(%rip), %r14
	movq	vars+928(%rip), %r15
	movq	%r15, %rbx
	pushq	%rbx
	pushq	$0
	popq	%rsi
	popq	%rdi
	cmpq	%rsi, %rdi
	jne	L002
	movq	%r12, %rbx
	pushq	%rbx
	popq	%rcx
	movq	%rcx, vars+800(%rip)
	pushq	$1
	popq	%r15
	movq	%r15, vars+928(%rip)
	jmp	L003
L002:
	movq	%r12, %rbx
	pushq	%rbx
	popq	%rdi
	neg	%rdi
	pushq	%rdi
	popq	%rcx
	movq	%rcx, vars+800(%rip)
	pushq	$0
	popq	%r15
	movq	%r15, vars+928(%rip)
L003:
	movq	%r14, %rbx
	pushq	%rbx
	movq	%r13, %rbx
	pushq	%rbx
	movq	%rcx, %rbx
	pushq	%rbx
	movq	$0, %rdx
	popq	%rsi
	popq	%rax
	idivq	%rsi
	pushq	%rax
	popq	%rsi
	popq	%rdi
	addq	%rsi, %rdi
	pushq	%rdi
	popq	%r14
	movq	%r14, vars+776(%rip)
	movq	%r12, %rbx
	pushq	%rbx
	pushq	$2
	popq	%rsi
	popq	%rdi
	subq	%rsi, %rdi
	pushq	%rdi
	popq	%r12
	movq	%r12, vars+880(%rip)
	movq	vars+880(%rip), %r12
	movq	vars+920(%rip), %r13
	movq	vars+776(%rip), %r14
	movq	vars+928(%rip), %r15
	jmp	L000
L001:
	movq	%r14, %rbx
	pushq	%rbx
	movq	%r13, %rbx
	pushq	%rbx
	pushq	$100000
	movq	$0, %rdx
	popq	%rsi
	popq	%rax
	idivq	%rsi
	pushq	%rax
	movq	$0, %rdx
	popq	%rsi
	popq	%rax
	idivq	%rsi
	pushq	%rax
	pushq	$4
	popq	%rsi
	popq	%rdi
	imulq	%rsi, %rdi
	pushq	%rdi
	movl	$formatString, %edi
	popq	%rsi
	xor	%rax, %rax
	call	printf
	leave
	ret

