#!/bin/bash

echo "Enter two numbers:"
read a
read b

temp=$a
a=$b
b=$temp

echo "After swapping:"
echo "a = $a"
echo "b = $b"