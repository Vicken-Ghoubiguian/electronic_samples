# import 'Pin' () and 'PMW' (for 'Pulse width modulation', to get an artificial analog output on a digital pin) classes from 'machine' module...
from machine import Pin, PWM

# import 'sleep' (function to suspend execution of the current thread for a given number of seconds) function from 'time' Python standard module...
from time import sleep

# instantiation a PWM object and open it corresponding to the specified pin (created here)...
pwm = PWM(Pin(25))

# set the current PWM object's frequency to 1 second...
pwm.freq(1000)

# we go into an infinite loop...
while True:

    #
    for duty in range(65025):
		pwm.duty_u16(duty)
		sleep(0.0001)
	 
	# 
    for duty in range(65025, 0, -1):
		pwm.duty_u16(duty)
		sleep(0.0001)