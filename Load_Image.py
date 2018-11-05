import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import numpy as np

lena=mpimg.imread('路径+文件名')
lena.shape
plt.imshow(lena)
plt.axis('off')
plt.show()
