#! /bin/bash

FILE_NAME="Employee.dat"

MAX_SAL=$(cat "$FILE_NAME" | cut -d"|" -f5 | sort -r | head -1)
echo $(grep ".*$MAX_SAL$" "$FILE_NAME" | cut -d"|" -f2)

tr ":" "|" $FILE_NAME


grep "marketing|[0-9]\+" $FILE_NAME | tr "[:lower:]" "[:upper:]"

cut -d"|" -f2 < $FILE_NAME | grep -i "gupta" | sort -ur

grep -A 3 "dgm" $FILE_NAME

grep "^[0-9]\{3\}|" $FILE_NAME > emp1.dat

for entry in *
do
    if [[ $entry =~ "^\." ]]; then continue; fi
    echo $entry
done;