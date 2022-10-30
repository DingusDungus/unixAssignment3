#!/bin/sh

file=$1

fileProperties=$(echo $file | tr "." "\n")

./calc3i.exe < $file > $fileProperties.s

echo "
.data
formatString:
	.string	\"Number :%d\n \"
vars:
	.zero	2048
isInReg:
	.zero	2048

.text
.global	main		
    
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	\$16, %rsp" | cat - $fileProperties.s > temp && mv temp $fileProperties.s

echo -e "	leave
	ret\n" >> $fileProperties.s

gcc -c $fileProperties.s 
gcc $fileProperties.o ./library_functions/lib/calc_lib.a -o $fileProperties.exec 
