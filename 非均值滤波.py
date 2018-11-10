import numpy as np 
import cv2 
from matplotlib import pyplot as plt 
bpath='C:\\Users\\23501\\Desktop\\map\\'
img = cv2.imread(bpath+'1.bmp') 
 
dst = cv2.fastNlMeansDenoisingColored(img,None,10,10,7,21) 
 
image = np.zeros(dst.shape, np.uint8)
image[:,:,0]=dst[:,:,2]
image[:,:,1]=dst[:,:,1]
image[:,:,2]=dst[:,:,0]
plt.imshow(image)

from PIL import Image
arr=np.array(image)
#将元素类型更改为'uint8'
arr=np.array(arr,dtype='uint8')
arr=Image.fromarray(arr)
#第一个参数为存储的地址和名称，第二个参数为存储的图片类型
arr.save('C:\\Users\\23501\\Desktop\\lena_new_sz.bmp','bmp')
