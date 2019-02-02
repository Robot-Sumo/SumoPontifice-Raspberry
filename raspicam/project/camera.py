from picamera import PiCamera
from time import sleep

camera = PiCamera()
camera.resolution = (640, 480)
camera.framerate = 90
camera.start_preview()
camera.start_recording('/home/pi/video.h264')
sleep(10)
camera.stop_preview()