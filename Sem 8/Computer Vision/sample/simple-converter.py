import binascii
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


if __name__ == "__main__":
    if not os.path.exists(OUTPUTS):
        os.mkdir(OUTPUTS)

    if not os.path.isdir(OUTPUTS):
        LOG.error("Output directory not accessable")
        exit

    # Loading an image
    img = Image.open(IMAGE)
    LOG.info("Loaded Image...")
    # img.show()

    # Show hex representation of a image
    with open(IMAGE, "rb") as f:
        hexdata = binascii.hexlify(f.read())
        with open(get_output_path("hex-version"), "wb") as fp:
            fp.write(hexdata)
    LOG.info("Hex Version of Image generated...")

    # Converting image to numpy array
    numpy_array = np.asarray(img)
    LOG.info("Saving numpy version of image...")
    np.save(get_output_path("numpy-ver.npy"), numpy_array)

    recreated_image = Image.fromarray(np.uint8(numpy_array))
    LOG.info("Recreated Image from Numpy Array...")
    recreated_image.save(get_output_path("recreated-from-numpy"), img.format)

    # Grayscale Image
    gray_img = img.convert("L")
    LOG.info("Grayscale Image...")
    gray_img.save(get_output_path("graysacle"), img.format)

    # Black & WHite image
    bw_img = img.convert("1")
    LOG.info("Black & White Image...")
    bw_img.save(get_output_path("black-white"), img.format)

    # JPEG
    LOG.info("Generated JPEG...")
    img.save(get_output_path("img.jpeg"), "jpeg")

    # PNG
    LOG.info("Generated PNG...")
    img.save(get_output_path("img.png"), "png")

    # WEBP
    LOG.info("Generated WEBP...")
    img.save(get_output_path("img.webp"), "webp")
