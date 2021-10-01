import numpy as np
import matplotlib.pyplot as plt

from sklearn.linear_model import Perceptron
from sklearn.model_selection import cross_val_score
from sklearn.metrics import accuracy_score, f1_score, precision_score, recall_score, roc_auc_score, roc_curve

def predict(weights, x_data):
    return 1 if np.dot(weights, x_data) >= 0 else 0


def plot_model(weights, x_data):
    fig, asx = plt.subplots()
    line_space = np.linspace(-5, 5)
    [w0, w1, w2] = weights
    m = -(w1/w2)
    c = -(w0/w2)
    asx.plot(line_space, line_space * m + c)

    for point in x_data:
        asx.plot(point[1], point[2], 'bo')

    plt.show()


def train_model(x_data, y_data, plot=False):
    weights = np.random.rand(len(x_data[0]))
    converged = False
    eta = 0.1
    while not converged:

        converged = True
        for x, y in zip(x_data, y_data):
            y_hat = predict(weights, x)

            if y_hat != y:
                weights = weights + (y - y_hat) * eta * x
                converged = False
        if plot:
            plot_model(weights, x_data)

    return weights


x_data = [[0, 0], [0, 1], [1, 0], [1, 1]]
y_data = {
    'AND': [0, 0, 0, 1],
    'OR': [0, 1, 1, 1],
    'NAND': [1, 1, 1, 0],
    'NOR': [1, 0, 0, 0]
}


padded_x = [np.array([1, x1, x2]) for [x1, x2] in x_data]
for mode in y_data:
    weights = train_model(padded_x, np.array(y_data[mode]))
    per = Perceptron(tol=0)
    per.fit(padded_x, y_data[mode])
    print(mode, weights, per.coef_[0], per.score(padded_x, y_data[mode]))

    y_pred = [predict(weights, x) for x in padded_x]
    y_pred_lib = [per.predict(x.reshape(1, -1)) for x in padded_x]
    print("Accuracy  : ", accuracy_score(y_data[mode], y_pred), accuracy_score(y_data[mode], y_pred_lib))
    print("Precision : ", precision_score(y_data[mode], y_pred), precision_score(y_data[mode], y_pred_lib))
    print("Recall    : ", recall_score(y_data[mode], y_pred), recall_score(y_data[mode], y_pred_lib))
    print("F1 Score  : ", f1_score(y_data[mode], y_pred), f1_score(y_data[mode], y_pred_lib))
    print("AUC Score : ", roc_auc_score(y_data[mode], y_pred), roc_auc_score(y_data[mode], y_pred_lib))







    


