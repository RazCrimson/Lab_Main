string = input("Enter the string: ")

previous_character = string[0]
count = 0
encoded_string = ""

for character in string:
    if character == previous_character:
        count += 1
    else:
        encoded_string += str(count) + previous_character
        previous_character = character
        count = 1
encoded_string += str(count) + previous_character

print(encoded_string)
