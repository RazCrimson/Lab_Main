#! /bin/bash

function print {
    echo $1 $1
}

read -p "Enter a number : " NUM
echo Result from print function: $(print $NUM)

source ./sample-script.sh
echo Result from square function: $(square $NUM)
