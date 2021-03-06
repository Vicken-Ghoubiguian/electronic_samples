# import 'Pin' (to manipulate pins) from 'machine' module...
from machine import Pin

# import the all 'time' Python standard module...
import time

# define the current pin object (the pin on the pico's board in this case) as the 'led' variable...
led = Pin(25, Pin.OUT)

# we go into an infinite loop...
while True:
    
  # light the pin...
  led.value(1)
  
  # suspend the execution for 1 milisecond...
  time.sleep(1.0)
  
  # switch off the pin...
  led.value(0)
  
  # suspend the execution for 1 milisecond...
  time.sleep(1.0)