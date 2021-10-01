import numpy as np
import matplotlib.pyplot as plt

from sklearn.linear_model import LinearRegression
from sklearn.metrics import accuracy_score, f1_score, precision_score, recall_score, roc_auc_score, roc_curve

def predict(weights, x_data):
    return np.dot(weights, x_data)


def plot_model(weights, x_data, y_data):
    fig, asx = plt.subplots()
    line_space = np.linspace(-5, 5)
    [w0, w1] = weights
    asx.plot(line_space, line_space * w1 + w0)

    for [_, x], y in zip(x_data, y_data):
        asx.plot(x, y, 'bo')

    plt.show()


def train_model(x_data, y_data, plot=False):
    weights = np.random.rand(len(x_data[0]))
    converged = False
    eta = 0.001
    while not converged:

        converged = False
        gd = [0 for _ in range(len(x_data[0]))]
        for x, y in zip(x_data, y_data):
            y_hat = predict(weights, x)

            if y_hat != y:
                weights += (y - y_hat) * x
                converged = False

        if np.all(np.abs(gd) <= 0.01):
            converged = True
        else:
            weights += 1e-3 * gd


        if plot:
            plot_model(weights, x_data, y_data)
    plot_model(weights, x_data, y_data)
    return weights

x_data = [4, 4.5, 5, 5.5, 6, 6.5, 7]
y_data = [33, 42, 45, 51, 53, 61, 62]

padded_x = np.array([[1, x] for x in x_data])


weights = train_model(padded_x, np.array(y_data))
model = LinearRegression()
model.fit(padded_x, y_data)
print(weights, model.coef_, model.score(padded_x, y_data))

# y_pred = [predict(weights, x) for x in padded_x]
# y_pred_lib = [model.predict(x.reshape(1, -1)) for x in padded_x]
# print("Accuracy  : ", accuracy_score(y_data, y_pred), accuracy_score(y_data, y_pred_lib))
# print("Precision : ", precision_score(y_data, y_pred), precision_score(y_data, y_pred_lib))
# print("Recall    : ", recall_score(y_data, y_pred), recall_score(y_data, y_pred_lib))
# print("F1 Score  : ", f1_score(y_data, y_pred), f1_score(y_data, y_pred_lib))
# print("AUC Score : ", roc_auc_score(y_data, y_pred), roc_auc_score(y_data, y_pred_lib))
