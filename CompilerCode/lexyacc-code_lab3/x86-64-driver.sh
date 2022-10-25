#!/bin/sh

file=$1

fileProperties=$(echo $file | tr "." "\n")

./calc3i.exe < $file > $fileProperties.s

echo -e "
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
    
main:" | cat - $fileProperties.s > temp && mv temp $fileProperties.s