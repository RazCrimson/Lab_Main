
def euclidean_distance(vec1: tuple, vec2: tuple):
    squared_result = 0
    if len(vec1) != len(vec2) or len(vec1) == 0:
        raise ValueError('Vector lengths are not equal')
    for x, y in zip(vec1, vec2):
        squared_result += (x - y) ** 2
    return squared_result ** 0.5


def cosine_angle(vec1: tuple, vec2: tuple):
    dot_product = 0
    magnitudes = [0, 0]
    if len(vec1) != len(vec2) or len(vec1) == 0:
        raise ValueError('Vector lengths are not equal')
    for x, y in zip(vec1, vec2):
        dot_product += x * y
        magnitudes[0] += x ** 2
        magnitudes[1] += y ** 2
    magnitudes[0] **= 0.5
    magnitudes[1] **= 0.5
    return dot_product/magnitudes[0]*magnitudes[1]

length = int(input('Enter the number of elements : '))
vec_1 = tuple([int(input(f'Enter vec 1 {x + 1}\'th element : ')) for x in range(length)])
vec_2 = tuple([int(input(f'Enter vec 2 {x + 1}\'th element : ')) for x in range(length)])

print('Euclidean Distance : ', euclidean_distance(vec_1, vec_2))
print('Cosine of Angle : ', cosine_angle(vec_1, vec_2))
