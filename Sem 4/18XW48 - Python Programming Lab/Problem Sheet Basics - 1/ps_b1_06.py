dictionary = {}

num = int(input("Enter the Number : "))
for i in range(1, num + 1):
    dictionary[i] = i ** 2
    
print(dictionary)