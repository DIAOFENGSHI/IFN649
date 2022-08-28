#!/usr/bin/python3.9
import paho.mqtt.client as mqtt
import serial
import time
import string


ser = serial.Serial("/dev/rfcomm2", 9600)

    # ser.write(str.encode('LED_ON\r\n'))
def on_connect(client, userdata, flags, rc): # func for making connection
    print("Connected to MQTT")
    print("Connection returned result: " + str(rc) )
    client.subscribe("ifn649/#")
def on_message(client, userdata, msg): # Func for Sending msg
    #print(msg.topic+" "+str(msg.payload))
    # print(len(str(msg.payload)))
    # print(len(str(msg.payload)))
    # if(len(str(msg.payload)) == 0):
        
    #     ser.write(str.encode('LED_OFF\r\n'))
    #     print(str(msg.payload))
    #     time.sleep(6)
    # else:
    # ser.write(str.encode('LED_ON'))
    x = str(msg.payload).split("'")
    print(x[1])
    y = x[1].split(" ")
    # time.sleep(5)
    z = float(y[2])
    
    if( z > 10 and z < 24):
        ser.write(str.encode('LED_GREEN_ON'))
   
    if(y[0] == "Soil" and z < 10):
        ser.write(str.encode('LED_RED_ON'))
   
    if(y[0] == "Temp" and z > 24): 
        ser.write(str.encode('LED_YELLOW_ON'))
    



client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
client.connect("unix.diaofengshi.com", 1883, 60)
client.loop_forever()

