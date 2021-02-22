
import random

def generate(n):
    result = [random.randint(0,n) for x in range(n)]
    return result

def frequency(list):
    result = {}
    for x in list:
        result[x] = list.count(x)
    return result

if __name__ == '__main__':
    generated_list = generate(100)
    frequency_dict = frequency(generated_list)
    print(frequency_dict)