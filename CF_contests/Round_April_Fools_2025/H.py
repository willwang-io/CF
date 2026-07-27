import cv2
import numpy as np

import cv2
import numpy as np

image = cv2.imread('./32158381cb329ae5f8a7c9122957b0279ca0e249.webp')

sharpen_kernel = np.array([[0, -1, 0],
                           [-1, 5, -1],
                           [0, -1, 0]])

sharpened = cv2.filter2D(image, -1, sharpen_kernel)
cv2.imwrite('sharpened_image.jpg', sharpened)
