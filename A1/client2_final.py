#!/usr/bin/python3.9
import paho.mqtt.client as mqtt
import serial
import time
import string


ser = serial.Serial("/dev/rfcomm2", 9600)

def checkEnvironment(message):
    infoArrary = str(message).split(" ")
    humidity = infoArrary[2]
    temperature = infoArrary[5]
    if(float(humidity) > 50.00 or float(temperature) > 28.00):
        return "DANGER" # danger situation
    else:
        if(float(humidity) > 40.00 and float(humidity) < 50.00 or float(temperature) > 25.00 and float(temperature) < 28.00 ):
            return "WARNING" # warning situation
        else:
            return "SAFE" # safe situation

def on_connect(client, userdata, flags, rc): # func for making connection
    print("Connected to MQTT")
    print("Connection returned result: " + str(rc) )
    client.subscribe("ifn649/#")

def on_message(client, userdata, msg): # Func for Sending msg

    print(str(msg.payload).split("'")[1])

    topic = str(msg.topic).split("/")[1]

    situationLevel = checkEnvironment(msg.payload)
    if(topic == "1201"):
            ser.write(str.encode(situationLevel + "1"))
            time.sleep(2)
    if(topic == "1202"):
            ser.write(str.encode(situationLevel + "2"))
            time.sleep(2)

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
client.connect("unix.diaofengshi.com", 1883, 60)
client.loop_forever()

