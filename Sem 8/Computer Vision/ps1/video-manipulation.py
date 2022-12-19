import logging
import os
import sys

import cv2
from PIL import Image, ImageChops

logging.basicConfig(level=logging.DEBUG, stream=sys.stdout)
LOG = logging.getLogger()
FILE_PATH = os.path.dirname(__file__)
OUTPUTS = os.path.join(FILE_PATH, "outputs")


def get_output_path(file_name: str) -> str:
    return os.path.join(OUTPUTS, file_name)


if __name__ == "__main__":
    if not os.path.exists(OUTPUTS):
        os.mkdir(OUTPUTS)

    if not os.path.isdir(OUTPUTS):
        LOG.error("Output directory not accessable")
        exit

    vid = cv2.VideoCapture(0)

    _, frame1 = vid.read()
    _, frame2 = vid.read()
    vid.release()

    img1 = Image.fromarray(frame1)
    img2 = Image.fromarray(frame2)

    difference = ImageChops.subtract(img1, img2)
    difference.save(get_output_path(f"frame-difference.jpg"), "JPEG")
