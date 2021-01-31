# Here probablistic normalization is performed.

def probablistic_normalization(input_list):
    list_sum = sum(input_list)
    result_list = []
    for num in input_list:
        result_list.append(num/list_sum)
    return result_list


length = int(input("Enter the number of elements in the list: "))
input_list = []
print("Enter the elements : ")
for _ in range(length):
    input_list.append(float(input()))
print("Normalized list is: ")
print(probablistic_normalization(input_list))