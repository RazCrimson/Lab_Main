n = int(input("Enter the number of elements in the list: "))
print("Enter the elements : ")

input_list = [int(input()) for _ in range(n)]
set_1 = set(input_list)

n = int(input("Enter the number of elements in set 2: "))
print("Enter the elements : ")

input_list = [int(input()) for _ in range(n)]
set_2 = set(input_list)


if set_1 == set_2:
    print("The two sets A and B are equal")
else:
    B1 = set_2-set_1
    B2 = set_1-set_2

    print(B1, B2)
    