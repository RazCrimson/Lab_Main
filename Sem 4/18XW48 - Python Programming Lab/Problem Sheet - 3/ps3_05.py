def func1(n):
    result = 0
    for i in range(n):
        x = '2'*(i+1)
        result += int(x)
    return result

if __name__ == '__main__':
    n = int(input('Enter the number of terms : '))
    output = func1(n)
    print(output)