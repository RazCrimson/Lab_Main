import math
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder
import sys

df = pd.read_csv("HousingData.csv")
x_data = df[df.columns.difference(['MEDV'])]
x_data['const'] = 1
y_data = df['MEDV']
x_train, x_test, y_train, y_test = train_test_split(x_data, y_data)
x_train = x_train.to_numpy()
x_test = x_test.to_numpy()
y_train = y_train.to_numpy()
y_test = y_test.to_numpy()
MAX_INT = sys.maxsize


def get_dist(x1, x2):
    dist = np.linalg.norm(x1 - x2)
    if np.isnan(dist):
        return MAX_INT
    return dist


def get_k_neighbours(x_train, y_train, k, x):
    dist = []
    for i in range(y_train.size):
        dist.append(tuple((i, get_dist(x_train[i], x))))
    dist.sort(key=lambda x: x[1])
    return dist[:k]


def get_pred(neighbours, y_train):
    dist = 0
    for i in range(len(neighbours)):
        dist += y_train[neighbours[i][0]]
    return dist/len(neighbours)


def get_model(x_train, x_test, y_train, y_test, k):
    SSE = 0
    for i in range(y_test.size):
        neighbours = get_k_neighbours(x_train, y_train, k, x_test[i])
        y_hat = get_pred(neighbours, y_train)
        SSE += (y_hat-y_test[i])**2
    return SSE


lowest_sse = MAX_INT
k = 1
best_k = 1
while True:
    if k == 27:
        break
    current_sse = get_model(x_train, x_test, y_train, y_test, k)*100
    if current_sse < lowest_sse:
        lowest_sse = current_sse
        best_k = k
    k += 2
print("Lowest SSE: ", lowest_sse)
print("Best value of K:  ", best_k)
