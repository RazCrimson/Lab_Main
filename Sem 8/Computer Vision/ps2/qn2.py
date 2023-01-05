import logging
import os
import sys

import numpy as np
from PIL import Image

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
    img1 = Image.open(IMAGE1)
    img = img1.convert("L")
    arr1 = np.asarray(img)
    LOG.info("Loaded Image...")

    img.save(get_output_path(f"original.{img1.format}"), img1.format)

    # Brighten
    result = arr1 * 1.2
    multiplied = Image.fromarray(np.uint8(result))
    multiplied.save(get_output_path(f"brighten.{img1.format}"), img1.format)

    # Divided
    result = np.uint8(arr1 / 2)
    divided = Image.fromarray(np.uint8(result))
    divided.save(get_output_path(f"darken.{img1.format}"), img1.format)
