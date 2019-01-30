import picamera
import time

def how_long(start, op):
    print('%s took %.2fs' % (op, time.time() - start))
    return time.time()

start = time.time()
with picamera.PiCamera() as camera:
    start = how_long(start, 'init')
    camera.resolution = (640, 480)
    start = how_long(start, 'set resolution')
    camera.framerate = 90
    start = how_long(start, 'set framerate')
    camera.video_stabilization = True
    start = how_long(start, 'set video_stabilization')
    camera.shutter_speed = 800
    start = how_long(start, 'set shutter_speed')
    camera.start_preview()
    start = how_long(start, 'start_preview')
    time.sleep(1)
    start = time.time()
    camera.capture('img14.jpg', 'jpeg', use_video_port=True)
    start = how_long(start, 'capture')