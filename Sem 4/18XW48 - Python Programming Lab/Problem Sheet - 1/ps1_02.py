def maximum_by_recursion(input_list):
    if (len(input_list) == 1):
        return input_list[0]
    else:
        present_maximum = maximum_by_recursion(input_list[1:])
        if(present_maximum < input_list[0]):
            return input_list[0]
        else:
            return present_maximum


n = int(input("Please enter the number of elements in the list: "))
print("Enter the list: ")
input_list = [int(input()) for _ in range(n)]

print("The maximum in the list is " + str(maximum_by_recursion(input_list)))