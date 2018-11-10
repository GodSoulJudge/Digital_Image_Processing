import cv2
import numpy as np
bpath='C:\\Users\\23501\\Desktop\\map\\'

fn=bpath+'1.bmp'
myimg=cv2.imread(fn)
img=cv2.cvtColor(myimg,cv2.COLOR_BGR2GRAY)


 
#滤波去噪
lbimg=cv2.medianBlur(newimg,3)
cv2.imshow('src',img)
cv2.imshow('dst',lbimg)
cv2.waitKey()
cv2.destroyAllWindows() 
