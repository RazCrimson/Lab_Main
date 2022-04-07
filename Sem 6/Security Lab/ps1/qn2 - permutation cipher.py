import math


class PermutationCipher:
    def __init__(self, n):
        self.n = n

    def encrypt(self, plaintext: str) -> str:
        if len(plaintext) % self.n != 0:
            raise Exception("Unpadded plaintext")

        rows = math.floor(len(plaintext) / self.n)
        return "".join([plaintext[(m * self.n) + n] for n in range(self.n) for m in range(rows)])

    def decrypt(self, plaintext: str) -> str:
        if len(plaintext) % self.n != 0:
            raise Exception("Invalid ciphertext")

        rows = math.floor(len(plaintext) / self.n)
        return "".join([plaintext[(m * rows) + n] for n in range(rows) for m in range(self.n)])


if __name__ == "__main__":
    pc = PermutationCipher(4)
    plain_text = "cryptography"
    cipher_text = pc.encrypt(plain_text)
    assert plain_text == pc.decrypt(cipher_text)
    print(f"Encrypting {plain_text} with PermitationCipher(4) results in `{cipher_text}`")

    string = "MYAMRARUYIQTENCTORAHROYWDSOYEOUARRGDERNOGW"
    for i in range(2, len(string)):
        pc = PermutationCipher(i)
        if len(string) % i == 0:
            print(pc.decrypt(string))
