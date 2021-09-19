import pandas as pd
import numpy as np
from matplotlib import pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder
import math

df = pd.read_csv('./dataset/iris.data')
EPOCH_LIMIT = 500

def sigmoid(x):
    return (1 + math.exp(-x)) ** -1

def predict(weights, x):
    return 1 if sigmoid(np.dot(weights, x)) >= 0.5 else 0

def logisticRegression(x_data, y_data, plot=False):
    weights = np.random.rand(x_data.shape[1])
    eta = 0.1
    
    for _ in range(EPOCH_LIMIT):       
        for i in range(len(x_data)):
            wTx = np.dot(weights, x_data[i])
            sig = sigmoid(wTx)

            y_hat = 1 if sig >= 0.5 else 0
            if y_hat != y_data[i]:
                weights = weights + (y_data[i] - sig) * eta * x_data[i]    
                continue
            break # Indicates convergence
    return weights

def test_model(weights, x_data, y_data):
    accurate_results = 0
    for i in range(len(x_data)):
        y_hat = predict(weights, x_data[i])
        if y_data[i] == y_hat:
            accurate_results += 1
    return accurate_results/len(x_data)


if __name__ == '__main__':
    df['const'] = 1

    iris_types = set(df['type'])
    for iris_type in iris_types:
        df_cpy = df.copy()
        df_cpy = df_cpy.replace(to_replace=[x for x in iris_types if x != iris_type], value=0)
        df_cpy = df_cpy.replace(to_replace=iris_type, value=1)

        x_data = df_cpy[df_cpy.columns.difference(['type'])]
        y_data = df_cpy['type']

        x_train, x_test, y_train, y_test = train_test_split(x_data.to_numpy(), y_data.to_numpy(), test_size=0.33)
        weights = logisticRegression(x_train, y_train, plot=True)
        accuracy = test_model(weights, x_test, y_test)
        print(iris_type)
        print("Weights : ", weights)
        print("Accuracy : ", accuracy * 100)
        