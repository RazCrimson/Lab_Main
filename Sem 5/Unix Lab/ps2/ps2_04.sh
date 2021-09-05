#! /bin/bash

if ! [ -f "$1" ]; then echo "Invalid File: $1" && exit 1; fi
echo "File exists"

stat --printf='Size: %s\nOwner: %U(&u)\nGroup: %G(%g)\nPermissions: %A(%a)\nLast Modified: %y\n' "$1"

if ! file -b "$1" | grep "text" &>/dev/null; then exit 0; fi


echo Number of words : $(wc -w "$1" | cut -f1)
echo Number of words having more than 5 characters: $(grep -o "[a-zA-Z]\{5,\}" "$1" | wc -l)
echo Number of words that start with a vowel: $(grep -o "\<[aeiouAEIOU][a-zA-Z]\+" "$1" | wc -l)
echo Number of articles in the text file: $(grep -o "\<(a\|the\|an\|A\|The\|An)\>" "$1" | wc -l)
# Access Permissions are already displayed stat
