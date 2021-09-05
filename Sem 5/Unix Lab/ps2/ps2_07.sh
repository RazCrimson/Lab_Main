#! /bin/bash

check=$(date +%H)
echo $check
if [ $check -ge 04 -a $check -le 12 ]; then
    echo "Good morning"
elif [ $check -gt 12 -a $check -le 17 ]; then
    echo "Good afternoon"
elif [ $check -gt 17 -a $check -le 20 ]; then
    echo "Good evening"
else
    echo "Good night"
fi
