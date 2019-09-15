# Assignment 1 - Create file with random and touch

#!/bin/bash

fileName=BatchJob$RANDOM

if [[ ! -f $fileName  ]]
  then
    touch $fileName
fi

echo $fileName
