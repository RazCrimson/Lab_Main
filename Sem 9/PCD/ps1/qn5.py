file = open('sample.c').readlines()
out = open('result.out', 'w+')
for i, line in enumerate(file):
    out.write(f"{i + 1} {line}")
