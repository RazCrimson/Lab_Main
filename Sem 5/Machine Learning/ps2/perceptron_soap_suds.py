import numpy as np
from matplotlib import pyplot as plt

def predict(weights, inputs):
    return np.dot(weights, inputs) 


def converge_fn(x, y):
    weights = np.random.rand(len(x[0]))
    epoch_counter = 0
    while True:
        epoch_counter += 1        
        gd = np.full(x.shape[1], 0, dtype=int)
        for i in range(x.shape[0]):
            y_hat = predict(weights, x[i])
            gd = gd + (y[i] - y_hat) * x[i]
            print(gd)

        if np.all(np.abs(gd) <= 0.01):
            break
        weights = weights + 1e-3 * gd
    print('Epochs : ', epoch_counter)
    return weights


def plot_epoch(weights, inputs, targets):
    range_x = np.linspace(-10, 10)
    fig, ax = plt.subplots()

    ax.plot(range_x, range_x * (weights[1] + weights[0]))

    for coord, target in zip(inputs, targets):
        ax.plot(coord[1], target, 'ro')

    plt.show()

data_set_x = [4, 4.5, 5, 5.5, 6, 6.5, 7]
data_y = [33, 42, 45, 51, 53, 61, 62]

x = np.array([[1, x] for x in data_set_x])
y = np.array(data_y)

weights = converge_fn(x , y)
print(f'Weights :', weights)
plot_epoch(weights, x, y)