#!/bin/bash

# Question 2 Manipulate files.

# Change your current working directory to OS
cd ~/OS

# Create a new subdirectory called assign2 in OS
mkdir assign2

# Create a new file called MyFile.txt
# using the touch command and insert two lines into the file
touch MyFile.txt
echo 'I like "Your Name"' > MyFile.txt
echo 'I like Chappathi' >> MyFile.txt

# Display the contents of the file MyFile.txt to the standard
# output (screen).
cat MyFile.txt

# Copy the file MyFile.txt to directory assign1 and rename it to t_1.txt.
cp MyFile.txt assign1/t_1.txt

# Change your working directory to assign1
cd assign1

# Make a copy of t_1.txt with the name t_2.txt (in the same directory).
cp t_1.txt t_2.txt

# Display the contents of the directory assign1.
ls ~/OS/assign1

# Copy the t_1.txt file to directory assign2.
cp t_1.txt ~/OS/assign2

# Display the contents of the directory assign2.
ls ~/OS/assign2

# Delete the file t_1.txt in the directory assign1.
rm t_1.txt

# Display the contents of the directory assign1.
ls ~/OS/assign1

