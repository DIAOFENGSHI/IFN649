# #!/usr/bin/python3

# import random
# import time
# import sys
# import struct
# import re
# #from bt.txt
# import serial
# import string
# from paho.mqtt import client as mqtt_client

# ser = serial.Serial("/dev/rfcomm0", 9600)
# broker = 'unix.diaofengshi.com'
# port = 1883
# topic = "Stone"

import time
import string
import paho.mqtt.publish as publish
import serial

A = False

broker = 'unix.diaofengshi.com'
ser = serial.Serial("/dev/rfcomm0", 9600)
while True:
    if ser.in_waiting > 0:
        rawserial = ser.readline()
        cookedserial = rawserial.decode('utf-8').strip('\r\n')
        print(cookedserial)
        x = cookedserial.split(" ")
        if(x[0] == "Soil"):
            publish.single("ifn649/soil", cookedserial, hostname=broker)
            A = False
        if(x[0] == "Temp"):
            publish.single("ifn649/Temp", cookedserial, hostname=broker)
            A = True


print("Done")