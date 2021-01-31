import numpy as np

print("Enter the number of rows and columns: ")
rows = int(input())
cols = int(input())
print('Enter the elements : ')
matrix = [[0 for _ in range(cols)] for _ in range(rows)]

for i in range(rows):
    for j in range(cols):
        matrix[i][j] = int(input())

matrix = np.array(matrix)
if (matrix == matrix.T).all():
    print("Symmetric")
product = np.dot(matrix, matrix.T)
np.fill_diagonal(product, 0)
if product.all() == 0:
    print("Orthogonal")    
