class CaesarCipher(object):

    def __init__(self, key):
        self.shift = key % 26
        # Use

    def encrypt(self, data):
        data_list = list(data)
        result = []
        for char in data_list:
            ascii_value = char
            if 65 <= char <= 91 or 97 <= char <= 122 :
                ascii_value += self.shift
                if 91 < ascii_value < 97 or ascii_value > 122:
                    ascii_value -= 26
            result.append(chr(ascii_value))
        return "".join(result).encode('utf-8')

    def decrypt(self, data):
        data_list = list(data)
        result = []
        for char in data_list:
            ascii_value = char
            if 65 <= char <= 91 or 97 <= char <= 122:
                ascii_value -= self.shift
                if ascii_value < 65 or 91 < ascii_value < 97:
                    ascii_value += 26
            result.append(chr(ascii_value))
        return "".join(result).encode('utf-8')
