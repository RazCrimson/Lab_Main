import itertools

import rsa
from modint import chinese_remainder


def are_coprime(a, b):

    hcf = 1

    for i in range(1, a + 1):
        if a % i == 0 and b % i == 0:
            hcf = i

    return hcf == 1


if __name__ == "__main__":
    number_of_receivers = 3

    # Fixing e to a particular value
    e = 3

    # Generating coprime n values
    not_coprime = True
    while not_coprime:
        pairs = [rsa.newkeys(16) for i in range(number_of_receivers)]
        n = [public_key.n for public_key, _ in pairs]
        if all(are_coprime(n1, n2) for n1, n2 in itertools.combinations(n, 2)):
            not_coprime = False

    message = 1123

    transmitted_messages = [pow(message, e, ni) for ni in n]

    print("n values: ", n)
    print("messages: ", transmitted_messages)

    retrieved = chinese_remainder(n, transmitted_messages)

    print(round(pow(retrieved, 1 / number_of_receivers)))
