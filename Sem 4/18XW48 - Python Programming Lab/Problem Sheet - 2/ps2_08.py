def caesar_encrypt(key, data):
    data_list = list(bytes(data, 'utf-8'))
    result = []
    for char in data_list:
        ascii_value = char
        if 65 <= char <= 91 or 97 <= char <= 122 :
            ascii_value += key
            if 91 < ascii_value < 97 or ascii_value > 122:
                ascii_value -= 26
        result.append(chr(ascii_value))
    return "".join(result).encode('utf-8')


key = int(input('Enter the key : '))
data = input('Enter the data to encrypt : ')
print(caesar_encrypt(key, data))
