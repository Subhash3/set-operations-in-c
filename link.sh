#!/bin/bash

for file in ./*
do
	x=$(echo $file | awk -F. '{print $3}')
	if [ $x = "c" ];
	then
		gcc -Wall -c $file
	fi
done
gcc -Wall *.o -o set_op

