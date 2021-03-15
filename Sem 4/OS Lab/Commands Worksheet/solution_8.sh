#!/bin/bash

echo "Author: Raz_Crimson  (19PW08)"

# Where is the bash program located on your system?
whereis bash

# Use the --version option to find out which version you are running.
whereis --version

# Create 3 variables, VAR1, VAR2 and VAR3; initialize them to hold the values
# thirteen, 13 and Happy Birthday respectively.
VAR1="thirteen"
VAR2=13
VAR3="Happy Birthday"

# Display the values of all three variables. Remove VAR3.
echo $VAR1 $VAR2 $VAR3
unset VAR3

# Can you see the two remaining variables in a new terminal window?
# No

# QN 6
ps -el
# Processes running with UID 0 can be considered 'system-wide' processes


# QN 7
# Can you use grep to see how many of your processes are running?
ps -U $UID
# The -U flag makes ps look for user specific processes with a list of UID which follows the -U flag
ps -el | grep $UID
# This is not same as -U flag as this also matches any line containing the same numbers as the UID


# QN 8
# Observation: you need read permission to list the files of a directory.
# You need write permission to create a file.

# QN 9
# Use a combination of cat (or more) and grep to display information in /etc/passwd about your own details
cat /etc/passwd | grep $UID

# What does this line mean?
# It represents the entry for my user account

# Which character is used to separate fields in the file?
# colon :

# How is your password stored?
# In a encrypted form

# If you try and access /etc/shadow what happens?
# Permission denied for normal user

# How many different shells can you find when looking at /etc/passwd file - which are they?
# 4
# /bin/bash
# /bin/zsh
# /usr/bin/nologin
# /usr/bin/git-shell

# QN 10
# I use zsh as my main shell, so my .zshrc has
alias rm='rm -r'
alias cl='clear'
alias ls='ls --color=auto'
alias zshconfig="nano ~/.zshrc"                                                                                                                                     
alias ohmyzsh="nano ~/.oh-my-zsh"                                                                                                                                   
alias dps="docker ps"                                                                                                                                               
alias dk="docker kill"                                                                                                                                              
alias dpsa="docker ps -a"                                                                                                                                           
alias drm="docker rm"

# QN 11
# Edit /etc/profile so that all users are greeted upon login (test this).
# Tested and verified by editing the file as root and using a command-line
# (non X session) to login

# QN 12
PS1="Danger!! root is doing stuff in \w > " >> ~/.bashrc # as root


# QN 13
ls -l | sort -k 5 --numeric-sort

# QN 14
# Display a list of all the users on your system who log in with the Bash shell as a default.
cat /etc/passwd | grep /bin/bash

# QN 15
# From the /etc/group directory, display all lines starting with the string &quot;daemon&quot;.
cat /etc/group | grep '^daemon'

# QN 16
# Print all the lines from the same file that don&#39;t contain the string.
cat /etc/group | grep -v '^daemon'

# QN 17
# Display localhost information from the /etc/hosts file, display the line number(s)
# matching the search string and count the number of occurrences of the string.
cat /etc/hosts | grep -n localhost
echo "Count : $(cat /etc/hosts | grep -c localhost)"

# QN 18
# Display a list of /usr/share/doc subdirectories containing information about shells.
find /usr/share/doc -name '*sh/README'

# QN 19
# How many README files do these subdirectories contain? Dont count anything in the form of README.a_string
find /usr/share/doc -wholename '*sh/README' | grep -v "README\..*"

# QN 20
# Make a list of files in your home directory that were changed less than 10 hours ago,
# using grep, but leave out directories.
find . -mmin -600

# QN 21
# Can you find an alternative for wc -l, using grep?
echo "grep -c '' <file>"

# QN 22
# Using the file system table (/etc/fstab for instance), list local disk devices.
cat /etc/fstab | grep -v "#"
# To actually list the devices connected to the system, 'fdisk -l' or gdisk might be a better choice

# QN 23
# Display configuration files in /etc that contain numbers in their names.
ls /etc | grep -e '[0-9]'

# QN 24
# The command top shows all processes (and other information about the system). Check it out.
# htop and glances other good morden alternatives to this.

# QN 25
sed -e '/^\s*$/d' -e '/^#/d' /etc/hosts

# QN 26
# setfacl and getfacl commands can be used to allow and modify Access Control Lists 
# which can leveraged to allow other users to access another user's home directory
