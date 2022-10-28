
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
	pushq	$732
	popq	%r12
	pushq	$2684
	popq	%r13
	pushq	%r12
	call fact_func
	movl	$formatString, %edi
	movq	%rax, %rsi
	xor	%rax, %rax
	call	printf
	pushq	%r12
	movl	$formatString, %edi
	movq	%r12, %rsi
	xor	%rax, %rax
	call	printf
	leave
	ret

