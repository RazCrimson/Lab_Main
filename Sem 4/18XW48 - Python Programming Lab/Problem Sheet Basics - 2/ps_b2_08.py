n = int(input("Enter the number of elements in the list: "))
print("Enter the elements : ")

input_list = [int(input()) for _ in range(n)]
set_1 = set(input_list)

n = int(input("Enter the number of elements in set 2: "))
print("Enter the elements : ")

input_list = [int(input()) for _ in range(n)]
set_2 = set(input_list)

print(set_1.union(set_2))
print(set_1.intersection(set_2))
print(set_1.symmetric_difference(set_2))