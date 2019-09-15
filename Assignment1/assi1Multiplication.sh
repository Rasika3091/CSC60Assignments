# Assignment 1 - Multiplication operation


#!/bin/bash

echo "I will be printing the multiplication table"

read -p "Please enter a number", num

# chech if input is integer
while ! [[ $num =~ ^-?[[0-9]+$ ]]
 do
    read -p "Invalid input. Please enter number : ", num
 done

for((x=1;x<6;x=x+1))
do
    echo "$x * $num = $(($x * $num))"
done


