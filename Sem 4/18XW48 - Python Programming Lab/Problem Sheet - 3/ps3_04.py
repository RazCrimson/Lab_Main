if __name__ == '__main__':
    user_input1 = list(input('Enter list -1 : ').split(" "))
    user_input2 = list(input('Enter list -2 : ').split(" "))
    result = []

    for (x, y) in zip(range(len(user_input1)), range(len(user_input2))):
        if x % 2 == 0:
            result.append(user_input1[x])
        if y % 2 == 1:
            result.append(user_input2[y])

    print(result)
