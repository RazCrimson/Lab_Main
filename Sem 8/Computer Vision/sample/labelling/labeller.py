import os

import numpy as np
from PIL import Image

FILE_PATH = os.path.dirname(__file__)
IMAGE = os.path.join(FILE_PATH, "labelling-shapes.png")


def is_neighbour(shape, x, y) -> bool:
    if x < 0 or y < 0 or x >= shape[0] or y >= shape[1]:
        return False
    return True


def label_pixels(img: Image):
    arr = np.asarray(img)
    shape = arr.shape
    labels = np.zeros(shape)
    label_counter = 1

    for j in range(shape[1]):
        for i in range(shape[0]):
            pt = i, j
            if arr[pt] == 1:
                continue

            diagonal = i - 1, j - 1
            if is_neighbour(shape, *diagonal) and arr[diagonal] == arr[pt]:
                labels[pt] = labels[diagonal]
                continue
            
            up = i, j -1
            left = i - 1, j
            up_match = is_neighbour(shape, *up) and arr[up] == arr[pt]
            left_match = is_neighbour(shape, *left) and arr[left] == arr[pt]

            if left_match and up_match and labels[left] != labels[up]:
                labels[labels == labels[up]] = labels[left]
            
            if left_match:
                labels[pt] = labels[left]
            elif up_match:
                labels[pt] = labels[up]
            else:
                labels[pt] = label_counter
                label_counter += 1
    
    return labels

if __name__ == "__main__":
    img = Image.open(IMAGE)
    img = img.convert("1")
    labels = label_pixels(img)
    unique_vals = np.unique(labels)
    
    counter = 0
    update = round(255 / len(unique_vals))
    for val in unique_vals:
        labels[labels == val] = counter
        counter += update

    res = Image.fromarray(np.uint8(labels))
    res.show()
