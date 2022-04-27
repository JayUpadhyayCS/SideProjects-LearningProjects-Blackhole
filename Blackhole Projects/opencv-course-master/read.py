import cv2 as cv

def rescaleFrame(frame, scale=0.75):
    width=int(frame.shape[1]*scale)
    height=int(frame.shape[0]*scale)
    dimensions=(width,height)
    return cv.resize(frame,dimensions,interpolation=cv.INTER_AREA)

img=cv.imread('Resources/Photos/cat.jpg')
img=rescaleFrame(img)
cv.imshow('Cat', img)
cv.waitKey(0)

def changeRes(width,height):
    capture.set(3,width)
    capture.set(4,height)
    

capture=cv.VideoCapture('Resources/Videos/dog.mp4')
while(True):
    isTrue,frame=capture.read() #reads in video fram by fram and saves into boolean whether it is read or not
    #frame=rescaleFrame(frame)
    cv.imshow("Video", frame)
    if cv.waitKey(20) & 0xFF==ord('d'):
        break
capture.release()
cv.destroyAllWindows()
