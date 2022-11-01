
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
	leave
	ret

	leave
	ret

	leave
	ret

	leave
	ret

