input_list = input('Enter the list : ')
input_list = input_list.split()
print([x for x in input_list if int(x)%2 == 0])
