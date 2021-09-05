#! /bin/bash

if [ $# -ne 1 ]; then
    echo "Script accepts only one argument"
    exit
fi

case $1 in
[0-9]) echo "Number" ;;
[a-z]) echo "Lower-case Letter" ;;
[A-Z]) echo "Upper-case Letter" ;;
[a-zA-Z0-9\ ]*) echo "Please enter a single character" ;;
*) echo "Special character" ;;
esac
