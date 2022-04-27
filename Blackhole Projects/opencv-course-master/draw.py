import cv2 as cv
import numpy as np

blank=np.zeros((500,500,3), dtype='uint8')
#paint image a certain color
blank[200:300, 300:400]=0,0,255

cv.imshow("blank", blank)

cv.rectangle(blank,(0,0),(250,250),(0,255,0),thickness=cv.FILLED)
cv.imshow("Rectangle", blank)
#img=cv.imread('Resources/Photos/cat.jpg')
#cv.imshow("Cat",img)
cv.circle(blank,(250,250),40,(255,0,0), thickness=3)
cv.imshow("Circle", blank)


cv.line(blank,(0,0),(250,250),(255,255,255),thickness=3)
cv.imshow("Line", blank)


#Write text

cv.putText(blank, "Hello", (225,225), cv.FONT_HERSHEY_TRIPLEX, 1.0, (0,255,0), 2)
cv.imshow("Text", blank)
cv.waitKey(0)