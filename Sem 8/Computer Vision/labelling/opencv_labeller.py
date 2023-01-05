import os
import cv2

FILE_PATH = os.path.dirname(__file__)
IMAGE = os.path.join(FILE_PATH, "labelling-shapes.png")

if __name__ == "__main__":
    connectivity = 6
    for img_path in [IMAGE, IMAGE2]:
        image = cv2.imread(img_path)
        gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
        thresh = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY_INV | cv2.THRESH_OTSU)[1]

        output = cv2.connectedComponentsWithStats(thresh, connectivity, cv2.CV_32S)
        (num_labels, labels, stats, centroids) = output

        for i in range(0, num_labels):

            if i == 0:
                text = "Examining component {}/{} (background)".format(i + 1, num_labels)
            else:
                text = "Examining component {}/{}".format(i + 1, num_labels)
            print("[INFO] {}".format(text))

            x = stats[i, cv2.CC_STAT_LEFT]
            y = stats[i, cv2.CC_STAT_TOP]
            w = stats[i, cv2.CC_STAT_WIDTH]
            h = stats[i, cv2.CC_STAT_HEIGHT]
            area = stats[i, cv2.CC_STAT_AREA]
            (c_x, c_y) = centroids[i]

            output = image.copy()
            cv2.rectangle(output, (x, y), (x + w, y + h), (0, 255, 0), 3)
            cv2.circle(output, (int(c_x), int(c_y)), 4, (0, 0, 255), -1)

            componentMask = (labels == i).astype("uint8") * 255

            cv2.imshow("Output", output)
            cv2.imshow("Connected Component", componentMask)
            cv2.waitKey(0)
