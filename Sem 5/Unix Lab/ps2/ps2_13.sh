#! /bin/bash

if [ "$#" -eq 0 ]; then
    DIR_PATH=( '.' )
else
    DIR_PATH=( $@ )
fi


echo "Files Larger than 10kb"
find ${DIR_PATH[@]} -type f -size +10240c

echo "Files Larger than 10kb and older than 10 days"
find ${DIR_PATH[@]} -type f -size +10240c -ctime 10

find ${DIR_PATH[@]} -type f -size +10240c -ctime 10 -printf ' %s \n' | echo $(expr $(paste -sd+)) bytes