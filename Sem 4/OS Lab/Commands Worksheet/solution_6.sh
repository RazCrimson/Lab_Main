#!/bin/bash

echo "Author: Raz_Crimson  (19PW08)"

# To print the name of operating system
uname -r

# To print the login name
echo $USER

# To print the host name
hostname

# Find out the users who are currently logged in and find the particular user too.
who

# Display the calendar for
# Jan 2000
cal jan 2000
# Feb 1999
cal feb 1999
# 9th month of the year 7 A.D
cal 9 7
# For the current month
cal
# Current Date Day Abbreviation , Month Abbreviation along with year
cal

# Display the time in 12-Hour and 24 Hour Notations.
echo 'Repeat of 5th Qn 35'

# Display the Current Date and Current Time.
echo 'Repeat of 5th Qn 36'

# Display the message “GOOD MORNING” in enlarged characters.
banner 'GOOD MORNING' # Does not work by default on Arch

# Display the name of your home directory.
echo $HOME

# Create a directory SAMPLE under your home directory.
mkdir ~/SAMPLE

# Create a sub-directory by name TRIAL under SAMPLE.
mkdir ~/SAMPLE/TRIAL

# Change to SAMPLE.
cd ~/SAMPLE

# Change to your home directory.
cd ~

# Change from home directory to TRIAL by using absolute and relative pathname.
cd ./SAMPLE/TRIAL
cd $HOME/SAMPLE/TRIAL

# Remove directory TRIAL.
rm -r ~/SAMPLE/TRIAL

# Create a directory TEST using absolute pathname.
mkdir ~/TEST

# Using a single command change from current directory to home directory.
cd ~

# Create empty files myfile and yourfile under Present Working Directory.
touch myfile yourfile

# Add some lines in the myfile and yourfile files.
echo 'Some random line\nblah blah blah' > myfile
echo 'Some random line2\nblah blah blah ver 2' > yourfile

# Display the files myfile and yourfile.
cat myfile yourfile

# Create a hidden file myhid.
touch .myhid

# Display all files in the current working directory
ls

# Display all files including hidden files in the current working directory
ls -a

# Copy myfile file to another file emp.
cp myfile emp

# Write the command to create alias name for the file myfile. ?
alias file_temp='myfile'

# Move yourfile file to another file dept.
mv yourfile dept

# Copy emp file and dept file to TRIAL directory
echo 'TRIAL dir already deleted. Recreating it'
mkdir ~/SAMPLE/TRIAL
cp emp ~/SAMPLE/TRIAL

# Compare a file with itself.
cmp dept dept

# Compare myfile file and emp file.
cmp myfile emp

# Append two more lines in emp file existing in TRIAL directory.
echo 'Extra lines \nYahallo~' >> ~/SAMPLE/TRIAL/emp

# Compare employee file with emp file in TRIAL directory.
cmp emp ~/SAMPLE/TRIAL/emp

# Find the difference between the above file.
diff emp ~/SAMPLE/TRIAL/emp

# Remove the files in the TRIAL directory.
rm -r ~/SAMPLE/TRIAL/*

# Remove a directory with files by using a single command?
# rm -r [dirname...]

# Is there any command available to get back a deleted file?
# extundelete is a possible choice for ext filesystems
# btrfs filesystems generally has periodic backup which can be used to restore
# Needs more research on other filesystems

# Rename TRIAL as DATA.
mv ~/SAMPLE/TRIAL ~/SAMPLE/DATA

# Copy DATA to another directory by name TRIAL.
cp ~/SAMPLE/DATA ~/SAMPLE/TRIAL

# Create a file called dummy in TRIAL and link it to another file by name star.
touch ~/SAMPLE/TRIAL/dummy
ln -T ~/SAMPLE/TRIAL/dummy ~/SAMPLE/TRIAL/star

# Print “Hello Welcome to OS Class” ?
echo 'Hello Welcome to OS Class'

# Get a value from the user and store it in a variable.
read RANDOM_VAR

# Print the value of the variable. 
echo  $RANDOM_VAR

# Make a variable as global
export RANDOM_VAR

# Write a command to perform numeric operation 11 + 11.
expr 11 + 11

# Print the result of 11 + 11 as ‘Result is 22’
echo "Result is $((11 + 11))"

# Read two integers into two variables and add them &amp; store it in a variable.
echo 'Enter the First Value: '
read FIRST
echo 'Enter the Second Value: '
read SECOND 
RESULT=$(($FIRST + $SECOND));

# Print the result as ‘Sum of &lt;first&gt; and &lt;second&gt; is &lt;result&gt;’
echo "Sum of $FIRST and $SECOND is $RESULT"

# Do all other arithmetic operations and print the result.
echo "Subtraction of $FIRST by $SECOND is $(($FIRST - $SECOND))"
echo "Multiplication of $FIRST and $SECOND is $(($FIRST * $SECOND))"
echo "Division of $FIRST by $SECOND is $(($FIRST / $SECOND))"
echo "Modulo of $FIRST by $SECOND is $(($FIRST % $SECOND))"
echo "Exponentiation of $FIRST by $SECOND is $(($FIRST ** $SECOND))"

# Try for floating point numbers.
echo 'Enter the First Value: '
read FIRST
echo 'Enter the Second Value: '
read SECOND 
echo "Addition of $FIRST with $SECOND is " $(echo "$FIRST + $SECOND" | bc -l)
echo "Subtraction of $FIRST by $SECOND is " $(echo "$FIRST - $SECOND" | bc -l)
echo "Multiplication of $FIRST and $SECOND is " $(echo "$FIRST * $SECOND" | bc -l)
echo "Division of $FIRST by $SECOND is " $(echo "$FIRST / $SECOND" | bc -l)
echo "Modulo of $FIRST by $SECOND is " $(echo "$FIRST % $SECOND" | bc -l)
echo "Exponentiation of $FIRST by $SECOND is " $(echo "$FIRST $SECOND" | awk '{print $1^$2;}')

# Login as root and create group as SS with id 501 &amp; DS with id 555
groupadd -g 501 ss
groupadd -g 555 ds

# Creating a list of users
useradd user1 -m -g 501 -s /bin/sh -G ds -c "user 1 user"
useradd user2 -m -u 502 -g 501 -s /bin/tcsh -c "user2 user"
useradd user3 -m -u 503 -g 501 -s /bin/bash -G ds -c "user3 user"
useradd user4 -m -u 504 -g 555 -s /bin/sh -c "user4 user"
useradd user5 -m -u 505 -g 555 -s /bin/bash -c "user5 user"

# Examine the content of the /etc/passwd file.
# user1:x:1002:501:user 1 user:/home/user1:/bin/sh
# user2:x:502:501:user2 user:/home/user2:/bin/tcsh
# user3:x:503:501:user3 user:/home/user3:/bin/bash
# user4:x:504:555:user4 user:/home/user4:/bin/sh
# user5:x:505:555:user5 user:/home/user5:/bin/bash

#Examine the content of the /etc/shadow file. Name the text that is found in the second
#field for the users created.
# The second field represents the password in a encrypted formant

# Set password for the users User1, User2, User3
passwd user1
passwd user2
passwd user3

# Select user2 from the list of users. Change the passwd aging information for user2
passwd -x 4 -i 2 user2

# Now change the system date increase by 5 days
date +%Y%m%d -s $(date -d "+5 days" +%Y%m%d)

# Logout of login session. Attempt to log as user2. What happens?
We receive a alert indicating that the password has expired and needs to be changed

# Change the shell for the user2 to Bourne shell.
chsh -s /bin/sh user2

# Delete user2 including his home directory and his comments.
userdel -r user2

# Lock the user1 with the help of a single command.
passwd -l user1 # or usermod -L user1

# Identify the available memory in the system.
free

# Display the list of devices connected to your system including the physical names and its
# instance number.
lspci
lsusb
lsblk

# Identify the number of hard disks connected to the system.
fdisk -l

# Login as a normal user
su user1

# Create file test
touch test

# Find the permissions of file test
ls -l

# Change the ownership of the file to user1
chown test user1

# Find the current umask setting
umask

# Change the umask setting
umask 0002

# Create file test1
touch test1

# Find out the difference
# The 0002 as the umask, the group memebers also get wite acces to the file

# Switch to Super User Account
su

# Change group of file test
chown :ds test

# Change ownership and group of file test1 with a single command
chown user4:ds test1

# Change the ownership of all the files in user1’s home directory with a single command
chown -R user3 /home/user1/*

# Create a file abc and turn the execute bit on
touch abc 
chmod +x abc

# Set setuid permission on the file abc
chmod u+s abc

# Determine if the setuid permission is enabled on the file abc
ls -l

# Create a directory testdir
mkdir testdir

# Set setgid permission on the testdir
chmod g+s -R testdir
chmod a+rw testdir # allow others to edit it

# Logout and login as user1
# Create a file testfile in testdir
touch testdir/testfile

# Verify the ownership and the group of the testfile
# The owner is the group of the parent dir due to setgid

# Switch to Superuser account
# Create a public directory dir1
mkdir /dir1
chmod a+rw /dir1

# Set stickybit (save text attribute) on dir1
chmod +t /dir1

# Logout and login as a normal user user1
# Create a file userfile1 in dir1
touch /dir1/userfile1

# Login as a different user user2
# Try to edit or remove the file
# Permission Denied

# Temporarily disable user logins
nano /etc/nologin

# List the processes for the current shell.
pstree $$ -g 

# Display information about processes.
top 

# Display the global priority of a process and find out the column that provides.
# The PR and NI columns of `top` displays the process priority

# Change the priority of a process with default arguments.
nice --15 ps

# Display Virtual Memory Statistics.
vmstat

# Display System Event Information.
journalctl # for Arch based distros

# Display Swapping Statistics.
# Check Buffer Activity statistics.
free

# Check Disk Activity statistics.
iotop # or iostat

# Check Inter process Communication statistics.
ipcs -a

# Check Unused Memory in the server.
# Check Swap Activities
free
