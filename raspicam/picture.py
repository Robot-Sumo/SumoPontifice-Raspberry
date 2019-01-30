from picamera import PiCamera
import time


camera = PiCamera()
time.sleep(2)

for i in range(10):
	time1 = time.time()
	camera.capture('/home/pi/raspicam/image.jpg')
	time2 = time.time()
	print((time2-time1)*1000)

print(camera.framerate)
print(camera.shutter_speed )