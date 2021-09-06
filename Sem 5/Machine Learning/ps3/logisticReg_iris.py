import pandas as pd
import numpy as np
import matplotlib as plt
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder
import math

df = pd.read_csv(
    '/home/raz/Projects/Lab_Main/Sem 5/Machine Learning/ps3/dataset/iris.data')
df = df[df['type'] != "Iris-virginica"]
df.head()

df['const'] = 1

label_encoder = LabelEncoder()
df['type'] = label_encoder.fit_transform(df['type'])

def sigmoid(x):
    return (1 + math.exp(-x)) ** -1


def predict(weights, x):
    return 1 if sigmoid(np.dot(weights, x)) >= 0.5 else 0


def logReg(x_data, y_data):
    weights = np.random.rand(x_data.shape[1])
    converged = False
    while not converged:
        converged = True
        for i in range(len(x_data)):
            y_hat = predict(weights, x_data[i])
            if y_hat != y_data[i]:
                weights = weights + (y_data[i] - sigmoid(np.dot(weights, x_data[i]))) * x_data[i]    
                converged = False
        print(weights)
    return weights


def test_model(weights, x_data, y_data):
    accurate_results = 0
    for i in range(len(x_data)):
        y_hat = predict(weights, x_data[i])
        if y_data[i] == y_hat:
            accurate_results += 1
    return accurate_results/len(x_data)


if __name__ == '__main__':
    x_data = df[df.columns.difference(['type'])]
    y_data = df['type']

    accuracies = []
    for _ in range(10):
        X_train, X_test, y_train, y_test = train_test_split(x_data.to_numpy(), y_data.to_numpy(), test_size=0.33)
        weights = logReg(X_train, y_train)
        accuracy = test_model(weights, X_train, y_train)
        accuracies.append(accuracy)
    print("Weights : ", weights)
    print("Accuracy : ", sum(accuracies)/len(accuracies))
        