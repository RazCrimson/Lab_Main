#!/bin/bash

# Create several empty files 'File1', 'mypersonaldetails', 'myfrienddetails',
# 'file2', 'file3' quickly by one command.
touch File1.txt mypersonaldetails.txt myfrienddetails.txt file2.txt file3.txt

# Store your personal data such as name, age, course, college, and city
# (separated by comma) into a file File1 and display the contents
echo "Bharath Vignesh J K, 19, SS, PSG tech, Coimbatore" > File1.txt
cat File1.txt

# Copy the contents of the file File1 into another file mypersonaldetails.
cp File1.txt mypersonaldetails.txt

# Create another file myfrienddetails to store the details given in question 2.
echo "Bharath Vignesh J K, 19, SS, PSG tech, Coimbatore" > myfrienddetails.txt

# Combine the contents of the files mypersonaldetails and myfrienddetails
# into another file details.txt.
cat myfrienddetails.txt mypersonaldetails.txt > details.txt

# Append the current date and time into the file details.txt.
date > details.txt

# Create the following directories using a
# single line command in your home directory.
# Dir1, Dir2, Dir3 and Dir4
mkdir ~/Dir1 ~/Dir2 ~/Dir3 ~/Dir4


# Move the file details.txt into Dir1.
mv details.txt ~/Dir1

# Delete the file File1.
rm File1.txt

# Change your current working directory to Dir1.
cd ~/Dir1

# Write the path of your current working directory.
pwd

# Go back to your home directory without using its name.
cd

# Copy the file details.txt into the directories Dir2, Dir3 and Dir4.
cp ~/Dir1/details.txt Dir2
cp ~/Dir1/details.txt Dir3
cp ~/Dir1/details.txt Dir4

# Create a directory Dir5 under Dir1.
mkdir ~/Dir1/Dir5

# Go to Dir5 using a single line command.
cd ~/Dir1/Dir5

# List all the files in your home directory.
ls ~

# Copy the file mypersonaldetails into Dir2 without changing the working directory
cp ~/OS/mypersonaldetails.txt ~/Dir2

# List all the files in your home directory.
echo "Same as second-last question"
# Delete the directory Dir3.
rm ~/Dir3 -r

# Create the following files : apple, orange1, orange2, orange3, pineapple, quartz.
# Write the output of the following commands.
# a) ls a?    b)ls a*    c)ls *.*    d)ls[!abc]ange    e) ls[a!bc]ange    f)ls[b-efg-z]*
touch apple.txt orange1.txt orange2.txt orange3.txt pineapple.txt quartz.txt
echo "a) no matches found: a?"
echo "b) apple.txt"
echo "c) apple.txt  orange1.txt  orange2.txt  orange3.txt  pineapple.txt  quartz.txt"
echo "d) event not found: abc]ange"
echo "e) event not found: bc]ange"
echo "f) orange1.txt  orange2.txt  orange3.txt  pineapple.txt  quartz.txt"

# List all the file names in which the character
# just before the last character is a digit.
ls -d *[0-9]?

# List all the files that starts with the letter a or b or c.
ls -d [abc]*

# Write the access permissions of files after each of the following command is executed.
# a) chmod  777 details.txt    b) chmodu+w g-w details.txt
# c)chmod 000 details.txt    d) chmodug+rw a=x details.txt
# e) chmodu+t Dir1
echo "a) -rwxrwxrwx"
echo "b) -rwxr-xrwx"
echo "c) ----------"
echo "d) ---x--x--x"
echo "e) drwxr-xr-x"

# Remove read and execute permissions for the owner of the file details.txt
chmod u-rx details.txt

# List all the files in your home directory along with the inode number
ls -ia

# Create a soft link for the file sum.txt and check the inode numbers
ln -s details.txt sum.txt

# Create a hard link for the file sum1.txt and place it under
# Dir2 and check the inode numbers
ln details.txt sum1.txt

# Create a link for the directory Dir1( check both hard and soft links).
ln -s ~/Dir1 sum.txt
ln ~/Dir1 sum1.txt

# Change the modification time of the file mypersonaldetails.txt
touch -m ~/OS/mypersonaldetails.txt

# List the files of the parent directory.
ls ../

# Append A Text File's Contents To Another Text File
cp ../details.txt copy.txt
cat ../details.txt >> copy.txt

# Display Line Numbers in File
wc -l copy.txt

# Find out the number of files in a directory.
ls | wc -l

# Create two regular files ‘file1’ and ‘file2’. Fill up the files with some text. Write a
# command to display the differences in the files, if any.
echo "My test string" > file1.txt
echo "My test string 1" > file2.txt
diff file1.txt file2.txt

# Display the time in 12-Hour and 24 Hour Notations
date +'%r'
date +'%R'

# Display Today’s date and time in the following format. DATE: 12/08/15 TIME:15:50:44
date +'DATE: %x TIME: %X'

# Display the calendar for the month of July in the year 2020
cal 07 2020

# Create the two files namely f1 and f2 with the following contents.
echo 'Henry\nMonty\nSumit\nCharlie\nJulie\nSumit' > f1
echo 'Charlie\nJulie\nMonty\nBob\nHarry' > f2

echo "Lines in f2 but not in f1: "
while IFS= read -r line;
do
    if ! grep -q $line f1; then
        echo $line
    fi
done < f2

# Combine the contents of f1 and f2 and display the details.
cat f1 f2

# Sorting Contents of Multiple Files in a Single File
sort f1 f2 | uniq > f0

# Write a command to display the following: “There are ______ files in the current directory.” (without the quotes)
echo "There are ______ files in the current directory."

# The ______ (dash) is to be replaced with the number of files in the current directory.
echo "There are $(ls -d | wc -l) file(s) in the current directory."
