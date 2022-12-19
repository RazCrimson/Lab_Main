import logging
import os
import sys

import numpy as np
from PIL import Image, ImageOps

logging.basicConfig(level=logging.DEBUG, stream=sys.stdout)
LOG = logging.getLogger()

FILE_PATH = os.path.dirname(__file__)
OUTPUTS = os.path.join(FILE_PATH, "outputs")
IMAGE1 = os.path.join(FILE_PATH, "inputs", "images", f"img1.jpeg")
IMAGE2 = os.path.join(FILE_PATH, "inputs", "images", f"img2.jpeg")


def get_output_path(file_name: str) -> str:
    return os.path.join(OUTPUTS, file_name)


def threshold(img: Image, lower_limit: int = 0, upper_limit: int = 255) -> Image:
    array = np.asarray(img1).copy()
    array[array < lower_limit] = lower_limit
    array[array > upper_limit] = upper_limit
    recreated_image = Image.fromarray(np.uint8(array))
    return recreated_image


if __name__ == "__main__":
    if not os.path.exists(OUTPUTS):
        os.mkdir(OUTPUTS)

    if not os.path.isdir(OUTPUTS):
        LOG.error("Output directory not accessable")
        exit

    # Loading an image
    img1 = Image.open(IMAGE1)
    img2 = Image.open(IMAGE2)
    arr1 = np.asarray(img1)
    arr2 = np.asarray(img2)
    LOG.info("Loaded Image...")

    # Generting Inverse
    inverse_img = ImageOps.invert(img1)
    LOG.info("Inverse Image...")
    inverse_img.save(get_output_path(f"inverse.{img1.format}"), img1.format)

    # Manual grayscale
    result = np.average(arr1, axis=2)
    recreated_gray = Image.fromarray(np.uint8(result))
    recreated_gray.save(get_output_path(f"manual-grayscale.{img1.format}"), img1.format)

    # Manual Black & White
    result = np.average(arr1, axis=2)
    result[result < 128] = 0
    result[result > 127] = 255
    recreated_bw = Image.fromarray(np.uint8(result))
    recreated_bw.save(get_output_path(f"manual-bw.{img1.format}"), img1.format)

    # Image addition
    result = arr1 + arr2
    recreated_added = Image.fromarray(np.uint8(result))
    recreated_added.save(get_output_path(f"image-add.{img1.format}"), img1.format)

    # Image subtraction
    result = arr1 - arr2
    recreated_added = Image.fromarray(np.uint8(result))
    recreated_added.save(get_output_path(f"image-sub.{img1.format}"), img1.format)

    # Image AND
    result = arr1 & arr2
    recreated_added = Image.fromarray(np.uint8(result))
    recreated_added.save(get_output_path(f"image-and.{img1.format}"), img1.format)

    # Image OR
    result = arr1 | arr2
    recreated_added = Image.fromarray(np.uint8(result))
    recreated_added.save(get_output_path(f"image-or.{img1.format}"), img1.format)

    # Image NOT
    result = ~arr1
    recreated_added = Image.fromarray(np.uint8(result))
    recreated_added.save(get_output_path(f"image-not.{img1.format}"), img1.format)

    # Image Tranlation
    result = np.roll(arr1, 300)
    translated_img = Image.fromarray(np.uint8(result))
    translated_img.save(get_output_path(f"image-translated.{img1.format}"), img1.format)

    # Image Rotation
    rotated = img1.rotate(90)
    rotated.save(get_output_path(f"image-rotated.{img1.format}"), img1.format)

    # Image Resize
    resized = img1.resize((400, 300))
    resized.save(get_output_path(f"image-resized.{img1.format}"), img1.format)

    # Image ROI
    cropped = img1.crop((0, 600, 300, 740))
    cropped.save(get_output_path(f"image-cropped.{img1.format}"), img1.format)

    thresholded_img = threshold(img1, 50, 200)
    thresholded_img.save(
        get_output_path(f"image-thresholded.{img1.format}"), img1.format
    )
