#!/bin/sh

file=$1

fileProperties=$(echo $file | tr "." "\n")

./calc3i.exe < $file > $fileProperties.s

echo -e ".data\n\tvars:\t.zero 1024\n\n" | cat - $fileProperties.s > temp && mv temp $fileProperties.s