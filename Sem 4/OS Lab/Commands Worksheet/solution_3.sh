#!/bin/bash

echo "Author: Raz_Crimson  (19PW08)"

# Question 3 Manipulate using wildcards

#Change your current working directory 
# to OS. (Stay in this directory for the rest of the steps )
cd ~/OS

# Create a new directory called assign3 in your working directory
mkdir assign3

# Create 9 new files (in directory OS) named as follows:
# Test_1.txt
# Test_2.txt
# Test_1-1.txt
# Test_2-1.txt
# Test_1-2.xtxt
# Test_2-2.xtxt
# Test_1-1.bak
# Test_2-2.bak
# File_1.bat
touch Test_1.txt Test_2.txt Test_1-1.txt Test_2-1.txt Test_1-2.xtxt Test_2-2.xtxt Test-1-1.bak Test_2-2.bak File_1.bak

# Display a listing of all the files in the working directory
ls

# Display a listing of all the files ending in txt using one command
ls *.txt

# Display a listing of all the files ending in t using one command.
ls *t

# Copy all the files containing "t_1" to the directory assign3 using one command.
cp $(ls *t_1*) assign3

# Display a listing of the contents of the directory assign3
ls assign3

# Use the "ls" command and list all files that contains "Test_2" in the filename.
ls *Test_2*

# Copy the content of all files that contain "Test_1" in their filename, 
# into a file called "tot.txt".
cat $(ls *Test_1*) >> tot.txt

# Write a single command that shows how many files you 
# have in your current working directory.
# Directories are exculded
find . -maxdepth 1 -type f | wc -l

# Make a list of your files into a file
ls > FileList.txt

# Assume that you are NOT currently in your home directory.  
# Enter a command to copy all files in your home directory
# beginning with the letter 'a' to the current directory
cp ~/a* ./

# Issue a command to delete all files in your current
# directory with 2-character names.
rm $(ls ??)

# Issue a command to delete one of the directory (in your home directory)
#  and all of its children. Use an absolute pathname 
rm $HOME/folder -r

# Enter a command to make the root directory your current directory.
cd /
