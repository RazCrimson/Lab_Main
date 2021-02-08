#!/bin/bash

# Print the disk usage of directory OS in bytes.
du -bs ~/OS

# Print the disk usage of the directory and all its files
du -b ~/OS

# Print the newline count, the byte count and the longest 
# line length for the file MyFile.txt in the directory OS
wc -lcL ~/OS/MyFile.txt

# Print the current date using the default format
date

# Print the current date in the format mm/dd/yy (example: 09/04/09).
date +'%D'

# What is the option to "ls" to list all files?
# Try it in your home directory.
# Which files do you see now that you don't see with "ls" alone?
ls -a

# What is the option to "ls" to list all files in all subdirectories. Try it
ls -R

# What is the command to count lines, words and characters in a file?
wc ~/OS/MyFile.txt

# How do you make this command display only the number of lines?
wc -l ~/OS/MyFile.txt

# Display the file "tot.txt" on the screen using "cat" command.
cat ~/OS/tot.txt

# Display the file "tot.txt" on the screen using more.
more ~/OS/tot.txt

# Test to walk upwards and downwards in the file using the "more" program.
more ~/OS/tot.txt

# Search for the word "Length" using the "more" and the "less" program, 
# compare the results.
echo "'less' is more efficient and easier to use than 'more'"

# Display the first 5 lines of the file "verylong.seq" on the screen.
head -5 verylong.seq

# Do a case insensitive search for the string "length" in all files.
grep -nR "length"

# Compare the files "1.txt", "2.txt" and "3.txt". Which one
# is different from the others?
diff 1.txt 2.txt 3.txt

# Put the first 7 and last 7 lines of the file "verylong.seq" 
# into a file called "first-and-last".
head -7 verylong.seq > first-and-last
tail -7 verylong.seq >> first-and-last

# List the names of all files in your whole account that 
# end with "seq" in their filename.
ls "*seq"

# List all files created or changed during the last 24 hours.
find . -type -f -mtime -1 -ls

# Find out who is logged on using "w", "who" and "finger".
w
who

# Find out which processes that are running using "top".
top

# Get more information about one account using "finger accountname" 
# where accountname is the name of the account.
finger $USER