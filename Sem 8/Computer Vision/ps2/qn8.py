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
IMAGE1 = os.path.join(FILE_PATH, "inputs", "hutao1.png")
IMAGE2 = os.path.join(FILE_PATH, "inputs", "hutao2.png")
IMAGE3 = os.path.join(FILE_PATH, "inputs", "hutao3.png")


def get_output_path(file_name: str) -> str:
    return os.path.join(OUTPUTS, file_name)


if __name__ == "__main__":

    if not os.path.exists(OUTPUTS):
        os.mkdir(OUTPUTS)

    if not os.path.isdir(OUTPUTS):
        LOG.error("Output directory not accessable")
        exit

    im1 = Image.open(IMAGE1)
    im2 = Image.open(IMAGE2)
    im3 = Image.open(IMAGE3)

    im1 = im1.transpose(Image.FLIP_LEFT_RIGHT)

    result_img = Image.new("RGBA", (sum(x.size[0] for x in [im1, im2, im3]), im1.size[1]))
    result_img.paste(im1, (0, 0))
    result_img.paste(im2, (im1.size[0], 0))
    result_img.paste(im3, (im1.size[0] + im2.size[0], 0))
    result_img.save(get_output_path("flipped-concated.png"), "PNG")
