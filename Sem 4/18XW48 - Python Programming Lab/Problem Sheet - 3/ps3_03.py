def divide_list(lst):
    ret_list = []
    for i in range(0, len(lst), 3):
        ret_list.append(lst[i:i + 3])
    return ret_list

if __name__ == '__main__':
    result = list(input('Enter the list : '))   
    print('Initial List : ', result)
     
    ret_list = divide_list(result)
    print('Divided lists : ')
    for lst in ret_list:
        print(lst)
        lst.reverse()

    print('Divided reversed lists : ')
    for lst in ret_list:
        print(lst)
