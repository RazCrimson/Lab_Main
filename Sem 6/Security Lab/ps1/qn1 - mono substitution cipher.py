import math
from enum import Enum
from typing import Iterable


class SubstituionMode(str, Enum):
    keyword = "keyword"
    col_transposition = "col_transposition"


class MonoAlphabeticSubstitutor:
    def __init__(self, key: str, mode: SubstituionMode = SubstituionMode.keyword):
        self.substitution_mode = mode
        self.key = "".join(self._key_gen(self.__clean_key(key)))

    @staticmethod
    def __clean_key(key: str) -> str:
        key = key.lower()
        result = ""
        for i in range(len(key)):
            if key[i] not in key[:i] and key[i].isalpha():
                result += key[i]

        if not result:
            raise Exception("Invalid Key")
        return result

    def _key_gen(self, key: str):
        if self.substitution_mode == SubstituionMode.keyword:
            return self._key_gen_by_keyword(key)
        return self._key_gen_by_columnar_transposition(key)

    def _generate_unique_alpha_sequence(key: str) -> Iterable[str]:
        alpha_count = 0
        for i in range(26):
            if i < len(key):
                yield key[i]
            else:
                while chr(alpha_count + 97) in key:
                    alpha_count += 1
                yield chr(alpha_count + 97)
                alpha_count += 1

    @staticmethod
    def _key_gen_by_keyword(key: str) -> Iterable[str]:
        return MonoAlphabeticSubstitutor._generate_unique_alpha_sequence(key)

    @staticmethod
    def _key_gen_by_columnar_transposition(key: str) -> Iterable[str]:
        matrix = "".join(MonoAlphabeticSubstitutor._key_gen_by_keyword(key))
        key_len = len(key)
        row_count = math.ceil(26 / key_len)

        for i in range(key_len):
            for j in range(row_count):
                if i + (j * key_len) >= 26:
                    break
                yield matrix[i + (j * key_len)]

    def __apply_transform(self, char: str) -> str:
        char = char.lower()
        return self.key[ord(char) - 97]

    def __reverse_transform(self, char: str) -> str:
        char = char.lower()
        return chr(self.key.find(char) + 97)

    def encrypt(self, plain_text: str) -> str:
        plain_text = plain_text.lower()
        cipher_text = ""
        for char in plain_text:
            if char.isalpha():
                cipher_text += self.__apply_transform(char)
            else:
                cipher_text += char

        return cipher_text

    def decrypt(self, cipher_text: str) -> str:
        cipher_text = cipher_text.lower()
        plain_text = ""
        for char in cipher_text:
            if char.isalpha():
                plain_text += self.__apply_transform(char)
            else:
                plain_text += char

        return plain_text


if __name__ == "__main__":
    x = MonoAlphabeticSubstitutor("CORNELL", SubstituionMode.col_transposition)
    print(x.encrypt("FAR ABOVE CAYUGA’S WATERS"))
