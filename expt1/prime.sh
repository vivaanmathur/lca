#!/bin/bash

echo "Enter a number:"
read n

flag=1

if [ $n -lt 2 ]
then
    flag=0
fi

for ((i=2; i<n; i++))
do
    if [ $((n % i)) -eq 0 ]
    then
        flag=0
        break
    fi
done

if [ $flag -eq 1 ]
then
    echo "$n is Prime"
else
    echo "$n is Not Prime"
fi