#!/bin/bash

echo "Enter three numbers:"
read a
read b
read c

if [ $a -gt $b ] && [ $a -gt $c ]
then
    echo "$a is largest"
elif [ $b -gt $c ]
then
    echo "$b is largest"
else
    echo "$c is largest"
fi