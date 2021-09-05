#! /bin/bash

clear
echo "enter password to lock the terminal"
read pass1
echo " Re-enter password"
read pass2
if [ "$pass1" = "$pass2" ]; then
    echo "system is locked"
    echo "enter password to unlock"
    trap ‘ ‘ 1 2 3 9 15 18
    while true; do
        read pass3
        if [ $pass1 = $pass3 ]; then
            echo "system unlocked"
            exit
        else
            echo "password mismatch"
        fi
    done
else
    echo "password mismatch"
fi
