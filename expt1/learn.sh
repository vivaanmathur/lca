#!/bin/bash

echo "Enter a number:"
read n

# if statement
if [ $n -gt 10 ]
then
    echo "$n is greater than 10"
elif [ $n -eq 10 ]
then
    echo "$n is equal to 10"
else
    echo "$n is less than 10"
fi


# Greater than or equal to
if [ $n -ge 18 ]
then
    echo "You are 18 or above"
else
    echo "You are below 18"
fi


# For loop
echo "For loop:"
for i in 1 2 3 4 5
do
    echo $i
done


# While loop
echo "While loop:"
i=1

while [ $i -le 5 ]
do
    echo $i
    i=$((i + 1))
done


# Case statement
echo "Enter your choice:"
echo "1. Hello"
echo "2. Good Morning"
echo "3. Exit"

read choice

case $choice in
    1)
        echo "Hello"
        ;;
    2)
        echo "Good Morning"
        ;;
    3)
        echo "Exit"
        ;;
    *)
        echo "Invalid choice"
        ;;
esac

