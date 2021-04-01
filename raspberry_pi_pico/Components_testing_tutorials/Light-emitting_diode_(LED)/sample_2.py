# import 'Pin' (to manipulate pins) from 'machine' module...
from machine import Pin

# definition of 2 leds at respectively pin 7 and 13...
led_1 = Pin(7, Pin.OUT)
led_2 = Pin(17, Pin.OUT)

# definition of the luminosity value of each led
led_1.value(0.5)
led_2.value(0.5)