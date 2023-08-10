import re
from pprint import pprint

NEWLINE = re.compile(r'\n')
DIGITS = re.compile(r'[0-9]')
WHITESPACE = re.compile(r'\n\t ')
ALPHABETS = re.compile(r'[a-zA-Z]')


file = open(__file__, 'r').read()

pprint(
    {
        'DIGITS': len(DIGITS.findall(file)),
        'ALPHABETS': len(ALPHABETS.findall(file)),
        'WHITESPACE': len(WHITESPACE.findall(file)),
        'NEWLINE': len(NEWLINE.findall(file)),
        'WORDS': len(file.split(' ')),
    }
)
