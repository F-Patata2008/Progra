#!/bin/bash

echo "Code to compile:"
read code

g++ $code -o ./tester
echo "The code $code was compiled Succesfully"

./tester < input.txt
