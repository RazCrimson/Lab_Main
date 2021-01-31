def number_fizz_bizz_selector(num: int):
    string = ''
    if num % 3 == 0:
        string += 'Fizz'
    if num % 5 == 0:
        string += 'Buzz'
    if string == '':
        string = str(num)
    return string

[print(number_fizz_bizz_selector(i)) for i in range(1, 101)]