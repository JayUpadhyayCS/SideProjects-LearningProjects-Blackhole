from configparser import Interpolation
import cv2 as cv

pic=cv.imread("IMG_6736.jpg")

gray=cv.cvtColor(pic,cv.COLOR_BGR2GRAY)

blur=cv.GaussianBlur(gray,(7,7),cv.BORDER_DEFAULT)
#cv.imshow("Boys",blur)
edge=cv.Canny(gray,125,175)
cv.imshow("CANNY",edge)


dilated= cv.dilate(edge,(3,3),iterations=3)
cv.imshow("dilated",dilated)


#eroding
eroded=cv.erode(dilated, (3,3), iterations=1)
cv.imshow("eroded", eroded)


#resize
resized=cv.resize(pic, (500,500), interpolation=cv.INTER_CUBIC)
cv.imshow("resized",resized)

#cropped
cropped= pic[50:200,200:400]
cv.imshow("cropped", cropped)
cv.waitKey(0)