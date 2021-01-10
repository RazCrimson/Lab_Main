n = int(input("Enter the number of elements in the list: "))
print("Enter the list elements : ")

input_list = [int(input()) for _ in range(n)]
input_set = set(input_list)

print('Number of Elements : ' + min(input_set) + '\n' + 'Max : ' + max(input_set))