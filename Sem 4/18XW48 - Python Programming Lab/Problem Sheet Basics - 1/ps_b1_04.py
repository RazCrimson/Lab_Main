string = input()
index, char = input().split(' ')
print(string[:int(index)] + char + string[int(index)+1:])
