import numpy as np

print("Enter the number of rows and columns: ")
rows = int(input())
cols = int(input())
matrix = [[0 for _ in range(cols)] for _ in range(rows)]

for i in range(rows):
    for j in range(cols):
        matrix[i][j] = int(input())

np_array = np.array(matrix)
print(np.linalg.inv(np_array))