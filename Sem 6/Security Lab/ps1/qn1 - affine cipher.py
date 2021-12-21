from typing import List


class AffineCipher:
    SIZE = 26
    def __init__(self, a:int, b:int):
        self.a = a
        self.b = b

    def _apply_transform(self, char: int) -> str:
        return ((self.a * char) + self.b) % self.SIZE

    def _reverse_transform(self, char: int) -> str:
        res = char - self.b
        inv = [x for x in range(1, 26) if (x * self.a) % self.SIZE == 1][0]
        return (inv * res) % self.SIZE

    def encrypt(self, string: str) -> str:
        result_string = ""
        for char in string:
            if 65 <= ord(char) <= 91:
                result_string += chr(self._apply_transform(ord(char) - 65) + 65)
            elif 97 <= ord(char) <= 122:
                result_string += chr(self._apply_transform(ord(char) - 97) + 97)
            else:
                result_string += char
        return result_string

    def decrypt(self, string: str) -> str:
        result_string = ""
        for char in string:
            if 65 <= ord(char) <= 91:
                result_string += chr(self._reverse_transform(ord(char) - 65) + 65)
            elif 97 <= ord(char) <= 122:
                result_string += chr(self._reverse_transform(ord(char) - 97) + 97)
            else:
                result_string += char
        return result_string

    
if __name__ == "__main__":
    ac = AffineCipher(5, 8)
    print(ac.decrypt("WZUSAAL"))

