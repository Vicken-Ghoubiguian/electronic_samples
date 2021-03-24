# import 'Pin' (to manipulate pins) from 'machine' module...
from machine import Pin

# definition of a led at pin 7...
led = Pin(7, Pin.OUT)

# definition of the luminosity value of this led
led.value(1)