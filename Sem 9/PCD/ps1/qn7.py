import re

TABS = re.compile(r'\t+')
SPACES = re.compile(r' +')
NEWLINES = re.compile(r'\n+')

file = open('sample.c').read()

file = TABS.sub('\t', file)
file = SPACES.sub(' ', file)
file = NEWLINES.sub('\n', file)

out = open('result.out', 'w+').write(file)
