#!/bin/bash

echo "Enter first number:"
read a

echo "Enter second number:"
read b

echo "Enter choice:"
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"

read choice

case $choice in
    1) echo "Sum = $((a + b))" ;;
    2) echo "Difference = $((a - b))" ;;
    3) echo "Product = $((a * b))" ;;
    4)
        if [ $b -eq 0 ]
        then
            echo "Division by zero not allowed"
        else
            echo "Quotient = $((a / b))"
        fi
        ;;
    *) echo "Invalid choice" ;;
esac