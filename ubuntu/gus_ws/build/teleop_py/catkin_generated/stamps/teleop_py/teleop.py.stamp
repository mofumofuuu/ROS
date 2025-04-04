#!/usr/bin/env python2.7
#encoding:utf-8 

import rospy
import serial
class teleop():
    def __init__(self):
        print("start")
        
        rospy.init_node("teleop_node")
        rospy.on_shutdown(self.onshutdown)
        self.connect()

    def connect(self):
        self.ser=serial.Serial(port="/dev/ttyAMA0",baudrate=115200)
        print("serial_open:"+ str(self.ser.isOpen()))

    def onshutdown(self):
        print("end")
    
if __name__== "__main__":
    teleop()