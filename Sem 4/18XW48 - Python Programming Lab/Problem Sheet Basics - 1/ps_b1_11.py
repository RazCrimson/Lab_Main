def is_keprekar(number):
    square = number * number
    length = len(str(number))
    square_str = str(square)
    right = int(square_str[-1*length:])
    left = int(square_str[:-1*length])
    if right + left == number:
        return True
    return False

num = int(input("Enter the number: "))
if is_keprekar(num):
    print("Keprekar number")
else:
    print("Not a Keprekar number")