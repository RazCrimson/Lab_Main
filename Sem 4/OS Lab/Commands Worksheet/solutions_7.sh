# Create a file dfile.txt with the following contents
# 123                                                                                        
# 123                                                                                                                
# 234                                                                                                                 
# 123                                                                                                                   
# 234                                                                                                   
# 567 
echo '123\n123\n234\n123\n234\n567\n' > dfile.txt

# I) Display the no of occurrence of the record
cat dfile.txt | sort | uniq -c

# II) Display only the duplicate records
cat dfile.txt | sort | uniq -d

# III) Display distinct records
cat dfile.txt | sort | uniq

# Create a file accounts.txt with the following contents
# ANU MANAGER
# KARTHIK ADMIN
# SHRIDAR HR
# BANU MANAGER
# VINOTH DIRECTOR
echo 'ANU MANAGER\nKARTHICK ADMIN\nSHRIDAR HR\NBANU MANAGER\nVINOTH DIRECTOR' > accounts.txt

# Find and replace the string ‘MANAGER’ with ‘ASSTMANAGER’ in the file accounts.txt
sed -e s/MANAGER/ASSTMANAGER/g accounts.txt

# The ls –i command displays a filename preceded by the inode number of the file
ls -i | sort
ls -i | sort -k 2


# List 5 last modified files
ls -lt | head -6

# QN 5
echo 'Raz Crimson\nFizzle\nLessa\nCabum\nEiri Chlo\nMort\nTsukin\n' > somerandomfile
cut -c-2 somerandomfile | tr a-z A-Z | sort -r > anotherfile

# QN 6
echo "Raz Crimson\nFizzle\nLessa\nCabum\nEiri Chlo\nMort\nTsukin\n" > name.txt
echo "1\n2\n3\n\4\n5\n6\n7\n" > reg.txt

paste reg.txt name.txt > anotherfile.txt

ls | grep .txt

# Display the common and distinct line of contents from a file(comm)
echo "Cabum\nEiri Chlo\nFizzle\nLessa\nMort\nRaz Crimson\nTsukin" > name01.txt
echo "Cabum\nFizzle\nRaz Crimson\nTeiwaze\nTetto\nTsukin" > name02.txt

comm -12 name01.txt name02.txt
comm -3 name01.txt name02.txt




