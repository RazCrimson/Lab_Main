import re

MACROS = re.compile(r'^[ \t]*#define[ \t]([a-zA-Z]+)[ \t](.+)$')

replacements = {}
file = open('sample.c').readlines()
out = open('result.out', 'w+')

for line in file:
    for replacement in filter(lambda x: x in line, replacements.keys()):
        line = line.replace(replacement, replacements[replacement])

    match = MACROS.match(line)
    if match:
        replacements[match.group(1)] = match.group(2)
    else:
        out.write(line)
