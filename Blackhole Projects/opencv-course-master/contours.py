from configparser import Interpolation
import cv2 as cv
import numpy as np

img=cv.imread("IMG_6736.jpg")
gray=cv.cvtColor(img, cv.COLOR_BGR2GRAY)
blur=cv.GaussianBlur(gray, (5,5), cv.BORDER_DEFAULT)
blank= np(img.shape[:2], dtype='uint8')
canny= cv.Canny(blur,125,175)
cv.imshow("Canny",canny)
#contours
ret, thresh= cv.threshold(gray, 125,255, cv.THRESH_BINARY)
contours, hierarchies= cv.findContours(thresh,cv.RETR_LIST, cv.CHAIN_APPROX_SIMPLE)
print(f'{len(contours)} contours found!')
 
cv.imshow("contours",thresh)



cv.waitKey(0)