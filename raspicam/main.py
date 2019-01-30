from picamera import PiCamera
from time import sleep


camera = PiCamera()
sleep(2)
camera.start_recording('/home/pi/raspicam/video.h264')
sleep(20)
camera.stop_recording()