# import 'Pin' (to manipulate pins) from 'machine' module...
from machine import Pin

#
led_1 = Pin(7, Pin.OUT)
led_2 = Pin(13, Pin.OUT)

#
led_1.value(0.5)
led_2.value(0.5)