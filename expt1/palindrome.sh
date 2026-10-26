#!/bin/bash

echo "Enter a number:"
read n

temp=$n
rev=0

while [ $temp -gt 0 ]
do
    digit=$((temp % 10))
    rev=$((rev * 10 + digit))
    temp=$((temp / 10))
done

if [ $n -eq $rev ]
then
    echo "$n is a Palindrome"
else
    echo "$n is not a Palindrome"
fi