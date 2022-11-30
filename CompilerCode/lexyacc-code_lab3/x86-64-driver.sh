#!/bin/sh

filepath=$1
filename=$(basename $1 .calc)
path=$(dirname $1)

rm -f $path/$filename.s $path/$filename $path/$filename.o

./calc3i.exe < $filepath > $path/$filename.s

echo "
.data
formatString:
	.string	\"Number :%d\n\"
vars:
	.zero	2048
isInReg:
	.zero	2048

.text
.global	main		
    
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	\$16, %rsp" | cat - $path/$filename.s > temp && mv temp $path/$filename.s

echo -e "	leave
	ret\n" >> $path/$filename.s

gcc -c $path/$filename.s -o $path/$filename.o
gcc -no-pie $path/$filename.o ./library_functions/lib/calc_lib.a -o $path/$filename
