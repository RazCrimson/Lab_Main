# QN 1 - Begins with a decimal digit: 0 through 9
grep '^[0-9]' sample.txt

# QN 2 - Begins with a hexadecimal digit: 0 through 9, a through f, or A through F.
grep '^[0-9a-fA-F]' sample.txt

# QN 3 - Entire line is a three-digit, decimal value.
grep '^[0-9]\{3\}$' sample.txt

# QN 4 - Entire line consists of hexadecimal digits
grep '^[0-9a-fA-F]\+$' sample.txt

# QN 5 - Entire line consists of alphabetic characters, either lower- or upper-case.
grep '^[a-zA-Z ]\+$' sample.txt

# QN 6 - Line contains a phone number of the form (217) xxx-xxxx
grep '(217) [0-9]\{3\}\-[0-9]\{4\}\>' sample.txt

# QN 7 - Line contains a phone number of the form (312) xxx-xxxx or (708) xxx-xxxx
grep '\<\((312)\|(708)\) [0-9]\{3\}\-[0-9]\{4\}\>' sample.txt

# QN 8  - Line has at least one period
grep '\.' sample.txt

# QN 9  - Line has a human-readable IP Address
grep '\<\(\(25[0-5]\|2[0-4][0-9]\|[01]\?[0-9][0-9]\?\)\.\)\{3\}\(25[0-5]\|2[0-4][0-9]\|[01]\?[0-9][0-9]\?\)\>' sample.txt

# QN 10 - Line with only an email address
grep "\<[a-zA-Z0-9+_.-]\+@[a-zA-Z0-9.-]\+\>" sample.txt # Simple mail address

# QN 11 - Line includes a quoted string; i.e., text enclosed within double quotes
grep '.*".\+".*' sample.txt

# QN 12 - Line includes a dollar amount with dollars and cents, such as $123.46.
# There must be at least one digit for the dollar amount and exactly two digits for the number of cents
grep '\$[0-9]\+\.[0-9]\{2\}' sample.txt

# QN 13 - Line is longer than 10 characters.
grep '^.\{11,\}$' sample.txt

# QN 14 - Line is shorter than 10 characters
grep '^.\{,9\}$' sample.txt

# QN 15 - All 7-letter words of the form b---da- (- is any lower case alphabet)
grep '\<b[a-z]\{3\}da[a-z]\>' sample.txt

# QN 16 - All words, exclusively lower-case, in which i immediately follows q.
grep '\<[a-z]*qi[a-z]*\>' sample.txt

# QN 17 - All words with either 22 or 23 letters
grep '\<[a-z]\{22,23\}\>' sample.txt

# QN 18 - All words which have all five vowels (a, e, i, o, and u) - in that order, interspersed with other non-vowels
grep '\<[a-zA-Z]*[aA][^aeiouAEIOU]\+[eE][^aeiouAEIOU]\+[iI][^aeiouAEIOU]\+[oO][^aeiouAEIOU]\+[uU][a-zA-Z]*\>' sample.txt






