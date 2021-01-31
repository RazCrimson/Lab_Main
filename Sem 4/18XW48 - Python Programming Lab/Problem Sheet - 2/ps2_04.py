triplets = set()
for i in range(1, 100):
    for j in range(1, 100):
        for k in range(1, 100):
            if i**2 + j**2 == k**2:
                triplets.add(frozenset({i, j, k}))

print('The triplets are : ')
for i, j, k in triplets:
    print(i, j, k)
