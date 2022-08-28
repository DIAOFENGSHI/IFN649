# #!/usr/bin/python3

import time
import string
import paho.mqtt.publish as publish
import serial

broker = 'unix.diaofengshi.com'
ser1 = serial.Serial("/dev/rfcomm0", 9600)
ser2 = serial.Serial("/dev/rfcomm1", 9600)

while True:
    if ser1.in_waiting > 0 or ser2.in_waiting > 0:
        rawserial1 = ser1.readline()
        rawserial2 = ser2.readline()
        cookedserial1 = rawserial1.decode('utf-8').strip('\r\n')
        cookedserial2 = rawserial2.decode('utf-8').strip('\r\n')
        print(cookedserial1 + " / " + cookedserial2)
        publish.single("ifn649/1201", cookedserial1, hostname=broker)
        time.sleep(2)
        publish.single("ifn649/1202", cookedserial2, hostname=broker)
        time.sleep(2)
            