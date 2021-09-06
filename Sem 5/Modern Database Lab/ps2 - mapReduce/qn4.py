import re
from typing import Any, List, Tuple


def mapper(file_obj, word_):
    data = []
    lines = file_obj.readlines()
    for ln_no, line in enumerate(lines):
        line = re.sub("[^0-9a-zA-Z]+", " ", line)
        for word in line.split():
            if word == word_:
                data.append((word, ln_no))
    return data


def partitioner(mapped_data: List[Tuple[str, Any]]):
    partitioned_data = {}
    for key, value in mapped_data:
        partitioned_data.setdefault(key, []).append(value)
    return partitioned_data


def reducer(partitioned_data):
    return [(key, sorted(part_data)) for key, part_data in partitioned_data.items()]


if __name__ == "__main__":
    word_ = input('Enter the word: ')
    file_1 = open("qn4.py")
    mapped = mapper(file_1, word_)
    part = partitioner(mapped)
    res = reducer(part)
    print(res)
