import magic
import sys
import os

file_path = sys.argv[1]
if os.path.isfile(file_path):
    file_type = magic.from_file(file_path)
    print(file_type)
else:
    print("Specified Path not a file")