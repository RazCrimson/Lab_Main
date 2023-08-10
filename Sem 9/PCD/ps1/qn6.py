import re

SINGLE_COMMENT = re.compile(r'//.*\n')
MULTILINE_COMMENT = re.compile(r"/\*(.|\n)*?\*/")

file = open('sample.c').read()

file = SINGLE_COMMENT.sub('\n', file)
file = MULTILINE_COMMENT.sub('\n', file)

out = open('result.out', 'w+').write(file)
