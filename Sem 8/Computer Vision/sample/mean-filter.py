import logging
import os
import sys

import numpy as np
from PIL import Image

logging.basicConfig(level=logging.DEBUG, stream=sys.stdout)
LOG = logging.getLogger()

FILE_PATH = os.path.dirname(__file__)
IMAGE = os.path.join(FILE_PATH, "img.jpg")
OUTPUTS = os.path.join(FILE_PATH, "outputs")


def get_output_path(file_name: str) -> str:
    return os.path.join(OUTPUTS, file_name)


def mean_filter(img: Image) -> Image:
    rows, cols = img.size
    arr = np.asarray(img)
    nw_arr = [[[] for _ in range(cols - 2)] for _ in range(rows - 2)]
    for i in range(rows - 2):
        for j in range(cols - 2):
            nw_arr[i][j] = np.average(arr[i : i + 3, j : j + 3])
    arr = np.array(nw_arr)
    return Image.fromarray(np.uint8(arr))


if __name__ == "__main__":
    if not os.path.exists(OUTPUTS):
        os.mkdir(OUTPUTS)

    if not os.path.isdir(OUTPUTS):
        LOG.error("Output directory not accessable")
        exit

    # Loading an image
    img = Image.open(IMAGE)
    LOG.info("Loaded Image...")

    filtered_img = mean_filter(img)
    filtered_img.save(get_output_path(f"filtered.{img.format}"), img.format)
