#Assignment 1 - Calculator

#!/bin/bash

echo "Welcome to my simple calculator (+,-,*,/)"

read -p  "Please enter first operand", op1
# check if input is integer
while ! [[ $op1 =~ ^-?[0-9]+$ ]]
 do
    read -p "Invalid input. Please enter a number", op1
 done

read -p  "Please enter second operand", op2
# check if input is integer
while ! [[ $op2 =~ ^-?[0-9]+$ ]]
do
  read -p "Invalid input. Please enter a number", op2
done

read -p  "Please enter the operator", operator

case $operator in

        "+") echo "$op1 $operator $op2 = $(($op1 + $op2))"
             ;;

        "-") echo "$op1 $operator $op2 = $(($op1 - $op2))"
             ;;

        "*") echo "$op1 $operator $op2 = $(($op1 * $op2))"
             ;;

        "/") # check if second operand in not 0 for divison
             while [[ op2 -eq 0 ]]
              do
               read -p "Cannot divide by 0. Please enter other operand", op2
              done
             
             echo "$op1 $operator $op2 = $(($op1 / $op2))" 
             ;;

        *)   echo "Invalid operator"
             ;;
esac


 


