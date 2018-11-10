import cv2 
import numpy as np 
from matplotlib import pyplot as plt  
bpath='C:\\Users\\23501\\Desktop\\map\\'
img = cv2.imread(bpath+'1.bmp')
dst = cv2.bilateralFilter(img,9,75,75) 
image = np.zeros(dst.shape, np.uint8)
image[:,:,0]=dst[:,:,2]
image[:,:,1]=dst[:,:,1]
image[:,:,2]=dst[:,:,0]
plt.imshow(image)
