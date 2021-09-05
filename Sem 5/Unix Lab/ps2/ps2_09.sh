#! /bin/bash

trap exit_handler SIGINT

exit_handler() {
    printf "\nExiting the program.....\n"
    exit
}

while true
do
    echo "THANK YOU"
    sleep 40
done