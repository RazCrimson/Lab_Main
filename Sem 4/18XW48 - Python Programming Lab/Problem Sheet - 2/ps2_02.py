
def euclidean_distance(vec1: tuple, vec2: tuple):
    squared_result = 0
    if len(vec1) != len(vec2) or len(vec1) == 0:
        raise ValueError('Vector lengths are not equal')
    for x, y in zip(vec1, vec2):
        squared_result += (x - y) ** 2
    return squared_result ** 0.5


length = int(input('Enter the number of elements : '))
vec_1 = tuple([int(input(f'Enter vec 1 {x + 1}\'th element : ')) for x in range(length)])
vec_2 = tuple([int(input(f'Enter vec 2 {x + 1}\'th element : ')) for x in range(length)])

print('Euclidean Distance : ', euclidean_distance(vec_1, vec_2))
