import re
from functools import reduce
from typing import Any, List, Tuple

def mapper(file_obj):
    data = []
    file_content = file_obj.read()
    file_content = re.sub("[^0-9a-zA-Z]+", " ",file_content)
    words = file_content.split()
    for word in words:
        data.append((word.lower(), 1))
    return data

def partitioner(mapped_data: List[Tuple[str, Any]]):
    partitioned_data = {}
    for key, value in mapped_data:
        partitioned_data.setdefault(key, []).append(value)
    return partitioned_data

def reducer(partitioned_data):
    return [(key, reduce(lambda x, y: x + y, part_data)) for key, part_data in partitioned_data.items()]

if __name__ == "__main__":
    file_1 = open("qn3.py")
    mapped = mapper(file_1)
    part = partitioner(mapped)
    res = reducer(part)
    print(res)
