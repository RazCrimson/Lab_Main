import numpy as np


class Cluster:
    THRESHOLD = 10

    def __init__(self, centroid: np.array):
        self.centroid = centroid
        self.elements = [centroid]

    def check_belonging(self, point: np.array) -> bool:
        return np.dot(self.centroid, point) > self.THRESHOLD

    def __str__(self) -> str:
        return f"{self.centroid}: {self.elements}"


if __name__ == "__main__":
    frequencies = np.array(
        [
            [1, 2, 0, 0, 1],
            [3, 1, 2, 3, 0],
            [3, 0, 0, 0, 1],
            [2, 1, 0, 3, 0],
            [2, 2, 1, 5, 1],
        ]
    )

    clusters = [Cluster(frequencies[:, 0])]

    for i in range(1, frequencies.shape[1]):
        point = frequencies[:, i]
        found = False
        for cluster in clusters:
            if cluster.check_belonging(point):
                cluster.elements.append(point)
                found = True
        if not found:
            clusters.append(Cluster(point))

    print("Clusters:")
    [print(cluster) for cluster in clusters]
