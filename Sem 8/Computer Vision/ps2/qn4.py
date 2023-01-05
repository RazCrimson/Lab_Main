import logging
import os
import sys

import numpy as np
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
    im1 = Image.open(IMAGE1)
    LOG.info("Loaded Image...")

    # Shapes
    draw = ImageDraw.Draw(im1)
    draw.line((0, 0) + im1.size, fill=(255, 0, 255, 255))
    draw.rectangle(((10, 20), (70, 60)), fill=(255, 100, 100, 255))
    draw.ellipse(((30, 30), (50, 50)), fill=(255, 255, 0, 255))
    draw.polygon(
        ((100, 100), (120, 80), (160, 190), (200, 200), (170, 210), (130, 250)),
        fill=(0, 255, 255, 255),
    )
    im1.save(get_output_path(f"shapes.png"), "PNG")

    # Text
    im = im1.convert("RGBA")
    shape_layer = Image.new("RGBA", im.size, (255, 0, 0, 0))
    draw = ImageDraw.Draw(shape_layer)
    draw.text((10, 10), "Hello", fill=(255, 255, 255, 128))
    draw.text((10, 60), "World", fill=(255, 255, 255, 255))

    out = Image.alpha_composite(im, shape_layer)

    out.save(get_output_path(f"text.png"), "PNG")
