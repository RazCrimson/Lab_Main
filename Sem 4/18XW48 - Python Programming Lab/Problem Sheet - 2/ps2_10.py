
def get_digits_count(num: int):
    digit_count = 0
    while num > 0:
        num //= 10
        digit_count += 1
    return digit_count

num = int(input('Enter a Number : '))
print('Digit Count  : ', get_digits_count(num))
