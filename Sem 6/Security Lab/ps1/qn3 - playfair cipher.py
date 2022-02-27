from typing import List


class PlayfairCipher:
    def __init__(self, key: str) -> None:
        key = self.__class__._validate_key(key)
        key_gen = self._key_gen(key)
        self._grid = [[next(key_gen) for _ in range(5)] for _ in range(5)]

    def _validate_key(key: str) -> str:
        key = key.lower()
        key = key.replace("j", "i")
        for i in key:
            if key.count(i) > 1:
                raise Exception("Invalid key!")
        return key

    @staticmethod
    def _key_gen(key: str):
        alpha_count = 0
        for i in range(25):
            if i < len(key):
                yield key[i]
            else:
                while chr(alpha_count + 97) in key or chr(alpha_count + 97) == "j":
                    alpha_count += 1
                yield chr(alpha_count + 97)
                alpha_count += 1

    @staticmethod
    def _split_and_pad_message(msg: str) -> List[str]:
        msg = "".join(ch for ch in msg if ch.isalpha())
        msg = msg.lower()
        result = []
        i = 0
        while i < len(msg):
            if i + 1 == len(msg) or msg[i] == msg[i + 1]:
                result.append(f"{msg[i]}z")
            else:
                result.append(msg[i : i + 2])
                i += 1
            i += 1
        return result

    def get_indices_in_grid(self, char):
        for i, row in enumerate(self._grid):
            for j, c in enumerate(row):
                if c == char:
                    return i, j
        raise Exception(f"Character not present : {char}")

    def _apply_transform(self, digraph: str) -> str:
        x1, y1 = self.get_indices_in_grid(digraph[0])
        x2, y2 = self.get_indices_in_grid(digraph[1])

        if y1 == y2:
            return self._grid[(x1 + 1) % 5][y1] + self._grid[(x2 + 1) % 5][y1]
        if x1 == x2:
            return self._grid[x1][(y1 + 1) % 5] + self._grid[x1][(y2 + 1) % 5]
        return self._grid[x1][y2] + self._grid[x2][y1]

    def _reverse_transform(self, digraph: str) -> str:
        x1, y1 = self.get_indices_in_grid(digraph[0])
        x2, y2 = self.get_indices_in_grid(digraph[1])

        if y1 == y2:
            return self._grid[(x1 - 1) % 5][y1] + self._grid[(x2 - 1) % 5][y1]
        if x1 == x2:
            return self._grid[x1][(y1 - 1) % 5] + self._grid[x1][(y2 - 1) % 5]
        return self._grid[x1][y2] + self._grid[x2][y1]

    def encrypt(self, word: str) -> str:
        padded_digraphs = self._split_and_pad_message(word)
        return "".join([self._apply_transform(digraph) for digraph in padded_digraphs])

    def decrypt(self, ciphered_word: str) -> str:
        ciphered_digraphs = [ciphered_word[i : i + 2] for i in range(0, len(ciphered_word), 2)]
        return "".join([self._reverse_transform(digraph) for digraph in ciphered_digraphs])


if __name__ == "__main__":
    f = open("plaintext")
    text = f.read()
    f.close()

    key = input("Enter the key: ") or "monarchy"
    pf = PlayfairCipher(key)
    cipher_text = "".join([pf.encrypt(word.lower()) for word in text.split()])
    split_cipher_text = [cipher_text[i : i + 5] for i in range(0, len(cipher_text), 5)]
    print("Result: ")
    for i in range(0, len(split_cipher_text), 10):
        print(" ".join(split_cipher_text[i : i + 10]))
