#!/bin/bash

echo "Enter file name:"
read file

echo "Enter word to search:"
read word

grep "$word" "$file"

if [ $? -eq 0 ]
then
    echo "Word found"
else
    echo "Word not found"
fi