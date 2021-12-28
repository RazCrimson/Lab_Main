class RandoCipher:
    def __init__(self, key: int) -> None:
        self.key = key

    def _apply_transform(self, char: int) -> str:
        result = char + self.key
        if result > 126:
            result = result - 95
        return chr(result)

    def _reverse_transform(self, char: int) -> str:
        # Assuming plain text as input
        if char - self.key + 95 > 126:
            return chr(char - self.key)  
        return chr(char - self.key + 95)
                  

    def encrypt(self, plain_text: str) -> str:
        return "".join(self._apply_transform(ord(char)) for char in plain_text)

    def decrypt(self, cipher_text: str) -> str:
        return "".join([self._reverse_transform(ord(char)) for char in cipher_text])


if __name__ == "__main__":  
    rc = RandoCipher(88)   
    print(rc.decrypt(":mmZ\dxZmx]Zpgy"))
