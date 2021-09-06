from functools import reduce


def mapReduce(mapper_func, reducer_func, *data):
    mapped_data = map(mapper_func, *data)

    partitioned_data = {}
    for key, value in mapped_data:
        partitioned_data.setdefault(key, []).append(value)

    return [(key, reduce(reducer_func, part_data)) for key, part_data in partitioned_data.items()]
