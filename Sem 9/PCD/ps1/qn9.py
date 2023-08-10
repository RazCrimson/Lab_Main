import re


STRING  = re.compile(r'"(.|\n)*?[^\\]"')
SINGLELINE_COMMENT = re.compile(r"//.*")
MULTILINE_COMMENT = re.compile(r"/\*(.|\n)*?\*/")
PREPROCESSOR  = re.compile(r'^#.*$', re.MULTILINE)
INTEGERS = re.compile(r"[+-]?0[0-8]+|0x[0-9a-fA-F]+|[0-9]+")
FLOATING_POINT = re.compile(r"[+-]?(\d+\.\d*([eE][+-]?\d+)?|\.\d+([eE][+-]?\d+)?)[fd]?")
OPERATORS = re.compile(r"(\+|-|\*|\/|%)=?|(<|>|!|=)=?|") #inclomplete
KEYWORDS_STRING = "auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while"
KEYWORDS = re.compile(f"(?<![0-9a-zA-Z])({KEYWORDS_STRING})(?![0-9a-zA-Z])")

res = open('sample.c').read()
res = PREPROCESSOR.sub("", res)
res = STRING.sub("", res)
res = SINGLELINE_COMMENT.sub("", res)
res = MULTILINE_COMMENT.sub("", res)
res = FLOATING_POINT.sub("", res)
res = INTEGERS.sub("", res)
res = KEYWORDS.sub("", res)
print(res)
