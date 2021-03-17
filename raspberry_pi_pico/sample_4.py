# import 'Pin' (to manipulate pins) and 'Timer' (to serve as timer) from 'machine' module...
from machine import Pin, Timer

# define the current pin object (the pin on the pico's board in this case) as the 'led' variable...
led = Pin(25, Pin.OUT)

#
timer = Timer()

# definition of the 'blink' function...
def blink(timer):
    
    # to toggle the 'status' of the pin (turn on to off and vice versa)...
    led.toggle()

#
timer.init(freq=2.5, mode=Timer.PERIODIC, callback=blink)