.data
	vars:	.zero 1024

main:
	pushq	$732
	popq	%eax
	pushq	$2684
	popq	%ecx
L000:
	pushq	%eax
	pushq	%ecx
	compNE
	jz	L001
	pushq	%eax
	pushq	%ecx
	compGT
	jz	L002
	pushq	%eax
	pushq	%ecx
	subq
	popq	%eax
	jmp	L003
L002:
	pushq	%ecx
	pushq	%eax
	subq
	popq	%ecx
L003:
	jmp	L000
L001:
	pushq	%eax
	print
	pushq	%eax
	pushq	%ecx
	gcd
	print
