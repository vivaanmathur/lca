#!/bin/bash

echo "Enter a number:"
read n

temp=$n
sum=0

while [ $temp -gt 0 ]
do
    digit=$((temp % 10))
    sum=$((sum + digit * digit * digit))
    temp=$((temp / 10))
done

if [ $sum -eq $n ]
then
    echo "$n is an Armstrong number"
else
    echo "$n is not an Armstrong number"
fi