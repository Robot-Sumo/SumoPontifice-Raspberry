#!/usr/bin/env python3
__author__ = 'Anton Vanhoucke'

import evdev


## Some helpers ##
def scale(val, src, dst):
    """
    Scale the given value from the scale of src to the scale of dst.

    val: float or int
    src: tuple
    dst: tuple

    example: print(scale(99, (0.0, 99.0), (-1.0, +1.0)))
    """
    return (float(val - src[0]) / (src[1] - src[0])) * (dst[1] - dst[0]) + dst[0]

def scale_stick(value):
    return scale(value,(0,255),(-100,100))

## Initializing ##
print("Finding ps3 controller...")
devices = [evdev.InputDevice(fn) for fn in evdev.list_devices()]
for device in devices:
    print(device)
    if device.name == 'PLAYSTATION(R)3 Controller':
        ps3dev = device.fn
        print("listo")

gamepad = evdev.InputDevice(ps3dev)

speed = 0
running = True



for event in gamepad.read_loop():   #this loops infinitely
    
    if event.type == 3:             #A stick is moved
        if event.code == 4:
            print(event.value)

        """            
        if event.code != 1 and event.code !=4 and event.code != 0 and event.code != 3:
           print (event)
        """
    




    
    if event.type == 1 and event.code == 302 and event.value == 1:
        print("X button is pressed. Stopping.")
        running = False
        break
    
    if event.type == 1:
        print(event)
