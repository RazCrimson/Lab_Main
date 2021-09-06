import json
from functools import reduce
from typing import Any, List, Tuple


def mapper(json_data):
    data = []
    for record in json_data:
        data.append((record['train_name'], record['station_name']))
    return data


def partitioner(mapped_data: List[Tuple[str, Any]]):
    partitioned_data = {}
    for key, value in mapped_data:
        partitioned_data.setdefault(key, []).append(value)
    return partitioned_data


def reducer(partitioned_data):
    return [(key, len(part_data)) for key, part_data in partitioned_data.items()]


if __name__ == "__main__":
    k = int(input('Enter the value of k: '))
    file_1 = open("schedules.json")  # URL: https://raw.githubusercontent.com/datameet/railways/master/schedules.json
    json_data = json.loads(file_1.read())
    mapped = mapper(json_data)
    part = partitioner(mapped)
    res = reducer(part)
    res.sort(key=lambda x: -x[1])
    print(res[:k])
