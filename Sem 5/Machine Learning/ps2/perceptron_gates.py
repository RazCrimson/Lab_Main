import numpy as np
from matplotlib import pyplot as plt


def predict(weights, inputs):
    return 1 if np.dot(weights, inputs) > 0 else 0


def plot_epoch(weights, inputs, targets):
    range_x = np.linspace(-5, 5)
    fig, ax = plt.subplots()

    if weights.shape[0] == 2:
        w_plot = weights / weights[1]
        ax.plot(np.array([-1 * w_plot[0]] * len(range_x)), range_x)
    else:
        w_plot = weights / weights[2]
        ax.plot(range_x, range_x * (-1 * w_plot[1]) + (-1 * w_plot[0]))

    for coord, target in zip(inputs, targets):
        color = 'ro'
        if target == 0:
            color = 'bo'

        if weights.shape[0] == 2:
            ax.plot(coord[1], 0, color)
        else:
            ax.plot(coord[1], coord[2], color)
    plt.show()


def converge_fn(coords, target):
    weights = np.random.rand(len(coords[0]))
    weight_start = None
    while True:
        weight_start = weights.copy()
        for i in range(len(target)):
            y_hat = predict(weights, coords[i])

            if target[i] != y_hat:
                if target[i] == 0:
                    weights -= coords[i]
                else:
                    weights += coords[i]
        plot_epoch(weights, coords, target)

        if np.array_equal(weights, weight_start):
            break
    return weights


if __name__ == '__main__':
    data_set_x = [[0, 0], [0, 1], [1, 0], [1, 1]]
    x = np.array([[1, x[0], x[1]] for x in data_set_x])

    targets_map = {
        'OR': [0, 1, 1, 1],
        'AND': [0, 0, 0, 1],
        # 'NOR': [1, 0, 0, 0],
        'NAND': [1, 1, 1, 0]
    }

    for mode_, target in targets_map.items():
        y = np.array(targets_map[mode_])
        weights = converge_fn(x, y)
        print(f'Weights for {mode_} :', weights)


    # NOT GATE
    data_set_x = [0, 1]
    x = np.array([[1, i] for i in data_set_x])
    y = np.array([1, 0])

    weights = converge_fn(x, y)
    print(f'Weights for NOT :', weights)
