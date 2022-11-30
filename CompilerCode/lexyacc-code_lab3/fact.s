	pushq	$0
	popq	%rdi
	call fact_func
	pushq	%rax
	pushq	$1
	popq	%rsi
	popq	%rdi
	subq	%rsi, %rdi
	pushq	%rdi
	movl	$formatString, %edi
	popq	%rsi
	xor	%rax, %rax
	call	printf
	pushq	$1
	popq	%rdi
	call fact_func
	pushq	%rax
	pushq	$1
	popq	%rsi
	popq	%rdi
	subq	%rsi, %rdi
	pushq	%rdi
	movl	$formatString, %edi
	popq	%rsi
	xor	%rax, %rax
	call	printf
	pushq	$2
	popq	%rdi
	call fact_func
	pushq	%rax
	pushq	$2
	popq	%rsi
	popq	%rdi
	subq	%rsi, %rdi
	pushq	%rdi
	movl	$formatString, %edi
	popq	%rsi
	xor	%rax, %rax
	call	printf
	pushq	$3
	popq	%rdi
	call fact_func
	pushq	%rax
	pushq	$6
	popq	%rsi
	popq	%rdi
	subq	%rsi, %rdi
	pushq	%rdi
	movl	$formatString, %edi
	popq	%rsi
	xor	%rax, %rax
	call	printf
	pushq	$4
	popq	%rdi
	call fact_func
	pushq	%rax
	pushq	$24
	popq	%rsi
	popq	%rdi
	subq	%rsi, %rdi
	pushq	%rdi
	movl	$formatString, %edi
	popq	%rsi
	xor	%rax, %rax
	call	printf
	pushq	$5
	popq	%rdi
	call fact_func
	pushq	%rax
	pushq	$120
	popq	%rsi
	popq	%rdi
	subq	%rsi, %rdi
	pushq	%rdi
	movl	$formatString, %edi
	popq	%rsi
	xor	%rax, %rax
	call	printf
	pushq	$6
	popq	%rdi
	call fact_func
	pushq	%rax
	pushq	$720
	popq	%rsi
	popq	%rdi
	subq	%rsi, %rdi
	pushq	%rdi
	movl	$formatString, %edi
	popq	%rsi
	xor	%rax, %rax
	call	printf
	pushq	$7
	popq	%rdi
	call fact_func
	pushq	%rax
	pushq	$5040
	popq	%rsi
	popq	%rdi
	subq	%rsi, %rdi
	pushq	%rdi
	movl	$formatString, %edi
	popq	%rsi
	xor	%rax, %rax
	call	printf
	pushq	$8
	popq	%rdi
	call fact_func
	pushq	%rax
	pushq	$40320
	popq	%rsi
	popq	%rdi
	subq	%rsi, %rdi
	pushq	%rdi
	movl	$formatString, %edi
	popq	%rsi
	xor	%rax, %rax
	call	printf
	pushq	$9
	popq	%rdi
	call fact_func
	pushq	%rax
	pushq	$362880
	popq	%rsi
	popq	%rdi
	subq	%rsi, %rdi
	pushq	%rdi
	movl	$formatString, %edi
	popq	%rsi
	xor	%rax, %rax
	call	printf
	pushq	$10
	popq	%rdi
	call fact_func
	pushq	%rax
	pushq	$3628800
	popq	%rsi
	popq	%rdi
	subq	%rsi, %rdi
	pushq	%rdi
	movl	$formatString, %edi
	popq	%rsi
	xor	%rax, %rax
	call	printf
	pushq	$11
	popq	%rdi
	call fact_func
	pushq	%rax
	pushq	$39916800
	popq	%rsi
	popq	%rdi
	subq	%rsi, %rdi
	pushq	%rdi
	movl	$formatString, %edi
	popq	%rsi
	xor	%rax, %rax
	call	printf
