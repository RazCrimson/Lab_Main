n = int(input("Enter the number of elements in the list: "))
print("Enter the list elements : ")

input_list = [int(input()) for _ in range(n)]
input_set = set(input_list)

print('Set: ' + input_set)
input_set.clear()
print('Set: ' + input_set)