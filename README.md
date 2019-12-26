# JSN-SR04T-2.0
Arduino library for communication with JSN-SR07T-2.0 ultrasonic sensor

<a>The jsn module can be used in three different modes:</a>
<a>Mode1: R27 open</a>

the basic working principle:

(1) using IO port TRIG trigger range, to a minimum of 10us high letter.

(2) module automatically send 8 40khz square wave, automatically detect whether there is a signal to return;

(3) a signal to return, through the IO port ECHO output a high level, high time is the duration of ultrasound from the launch to the return time. Test distance = (high time * speed of sound (340M / s)) / 2;

(4) module is triggered after the distance measurement, if you cannot receive the echo (the reason exceeds the measured range or the probe is not on the measured object), ECHO port will automatically become low after 60MS, marking the End of measurement, whether successful or not.

Mode2: R27 47kOhm

Serial output format for the TTL level, that: 100MS module for the cycle of automatic output distance value, the unit is mm. Serial baud rate: 9600, n, 8,1.

Mode3: R27 120kOhm

After the module is powered on, the module enters standby mode. The serial output format is TTL level, serial port baud rate: 9600, n, 8,1. When the RX port receives the 0X55 instruction, the module starts a ranging and outputs one frame from the pin TX with four 8-bit data.

Only Mode2 and Mode3 are supported in this version

In Jsn.h define mode2 or mode3 and Serial2 pins TX and RX 
