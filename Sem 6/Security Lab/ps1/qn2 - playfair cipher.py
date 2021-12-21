from typing import List
from pprint import pprint
class PlayfairCipher:
    def __init__(self, key: str) -> None:
        key = self.__class__._validate_key(key)
        key_gen = self._key_gen(key)
        self._grid = [[next(key_gen) for _ in range(5)] for _ in range(5)]
        pprint(self._grid)

    def _validate_key(key: str) -> str:
        key = key.lower()
        key = key.replace("j", 'i')
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
            

                


        


if __name__ == "__main__":
    print(PlayfairCipher._split_and_pad_message("helloe"))
