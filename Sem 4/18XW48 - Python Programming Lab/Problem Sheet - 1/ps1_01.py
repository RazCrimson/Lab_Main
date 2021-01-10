input_string = input("Enter the string: ")
input_set = set(input_string)    
[print(char + ": " + str(input_string.count(char))) for char in input_set]