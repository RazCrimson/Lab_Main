import math
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder

df = pd.read_csv("breast-cancer-wisconsin.csv")
df = df.loc[:, ~df.columns.str.contains('^Unnamed')]
x_data = df[df.columns.difference(['diagnosis'])]
x_data['id'] = 1
y_data = df['diagnosis']
le = LabelEncoder()
y_data = le.fit_transform(y_data)
x_train, x_test, y_train, y_test = train_test_split(x_data, y_data)
x_train = x_train.to_numpy()
x_test = x_test.to_numpy()


def get_dist(x1, x2):
    return np.linalg.norm(x1 - x2)


def get_k_neighbours(x_train, y_train, k, x):
    dist = []
    for i in range(y_train.size):
        dist.append(tuple((i, get_dist(x_train[i], x))))
    dist.sort(key=lambda x: x[1])
    return dist[:k+1]


def get_pred(neighbours, y_train):
    count_0 = 0
    count_1 = 0
    for i in range(len(neighbours)):
        if y_train[neighbours[i][0]] == 0:
            count_0 += 1
        else:
            count_1 += 1
    return 1 if count_1 > count_0 else 0


def get_model(x_train, x_test, y_train, y_test, k):
    correct_pred = 0
    for i in range(y_test.size):
        neighbours = get_k_neighbours(x_train, y_train, k, x_test[i])
        y_hat = get_pred(neighbours, y_train)
        if y_hat == y_test[i]:
            correct_pred += 1
    return correct_pred/y_test.size


best_accuracy = 0
k = 1
best_k = 1
while True:
    if k == 27:
        break
    current_accuracy = get_model(x_train, x_test, y_train, y_test, k)*100
    if current_accuracy > best_accuracy:
        best_accuracy = current_accuracy
        best_k = k
    k += 2
print("Best Accuracy: ", best_accuracy)
print("Best value of K:  ", best_k)
