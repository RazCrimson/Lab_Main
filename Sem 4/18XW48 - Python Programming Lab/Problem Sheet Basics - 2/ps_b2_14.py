n = int(input("Enter the number of elements in the list: "))
print("Enter the list elements : ")

input_list = [int(input()) for _ in range(n)]
print(set(input_list))
