#! /bin/bash

echo"Enter string"
read str

length=$(echo $str | wc -c)
length=$(echo $length - 1 | bc)
if [ $length -lt 12 ]; then
    while [ true ]; do
        clear
        sleep 1
        echo $str
        sleep 1
    done
else
    echo “string length greater than 12 characters”
fi
