import os

import numpy as np
from PIL import Image

FILE_PATH = os.path.dirname(__file__)
OUTPUTS = os.path.join(FILE_PATH, "outputs")
IMAGE1 = os.path.join(FILE_PATH, "labelling-shapes.png")
IMAGE2 = os.path.join(FILE_PATH, "labelling-connectivity.png")


def get_output_path(file_name: str) -> str:
    return os.path.join(OUTPUTS, file_name)


def is_neighbour(shape, x, y) -> bool:
    if x < 0 or y < 0 or x >= shape[0] or y >= shape[1]:
        return False
    return True


def label_pixels(img: Image, six_connectivity: bool = True):
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
            if six_connectivity and is_neighbour(shape, *diagonal) and arr[diagonal] == arr[pt]:
                labels[pt] = labels[diagonal]
                continue

            up = i, j - 1
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
    if not os.path.exists(OUTPUTS):
        os.mkdir(OUTPUTS)

    if not os.path.isdir(OUTPUTS):
        LOG.error("Output directory not accessable")
        exit

    connectivities = [False, True]
    for img_path in [IMAGE1, IMAGE2]:
        img = Image.open(img_path)
        img = img.convert("1")

        for enable_6_conn in connectivities:
            pixel_labels = label_pixels(img, enable_6_conn)

            counter = 0
            unique_vals = np.unique(pixel_labels)
            update = round(255 / len(unique_vals))
            for val in unique_vals:
                pixel_labels[pixel_labels == val] = counter
                counter += update

            res = Image.fromarray(np.uint8(pixel_labels))
            file_name = os.path.basename(img_path)
            res.save(get_output_path(f"{6 if enable_6_conn else 4}-connectivity-{file_name}"))
