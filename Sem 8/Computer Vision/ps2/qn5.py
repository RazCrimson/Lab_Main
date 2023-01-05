import logging
import os
import sys

import numpy as np
from matplotlib import pyplot as plt
from PIL import Image, ImageDraw

logging.basicConfig(level=logging.DEBUG, stream=sys.stdout)
LOG = logging.getLogger()

FILE_PATH = os.path.dirname(__file__)
OUTPUTS = os.path.join(FILE_PATH, "outputs")
IMAGE1 = os.path.join(FILE_PATH, "inputs", "img1.jpeg")


def get_output_path(file_name: str) -> str:
    return os.path.join(OUTPUTS, file_name)


if __name__ == "__main__":

    if not os.path.exists(OUTPUTS):
        os.mkdir(OUTPUTS)

    if not os.path.isdir(OUTPUTS):
        LOG.error("Output directory not accessable")
        exit

    # Loading an image
    im = Image.open(IMAGE1)
    LOG.info("Loaded Image...")
    arr = np.asarray(im.convert("L"))

    row_200 = [(i + 1, val) for i, val in enumerate(arr[200, :])]
    plt.plot(row_200)
    plt.title("Row 200")
    plt.xlabel("Pixel Index (Width)")
    plt.ylabel("Pixel Value in Grayscale (0-255)")
    plt.show()

    col_300 = [(i + 1, val) for i, val in enumerate(arr[:, 300])]
    plt.plot(col_300)
    plt.title("Column 300")
    plt.xlabel("Pixel Index (Height)")
    plt.ylabel("Pixel Value in Grayscale (0-255)")
    plt.show()
