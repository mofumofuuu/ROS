#!/usr/bin/env python2.7
#encoding:utf-8 

import rospy
import serial
from geometry_msgs.msg import Twist
class teleop():
    def __init__(self):
        print("start")
        
        rospy.init_node("teleop_node")
        rospy.on_shutdown(self.onshutdown)
        rospy.Subscriber("/cmd_vel",)
        self.connect()
        self.send_data_base()

    def connect(self):
        count = 0
        while count <=5:
            count +=1
            try:
                self.ser=serial.Serial(port="/dev/ttyAMA0",baudrate=115200)
                print("serial_open:"+ str(self.ser.isOpen()))
                
            except Exception as e:
                print(e)
        #rospy.spin()#阻塞


    def onshutdown(self):
        self.ser.close()
        print("end")
    def send_data_base(self):
        
        data = bytearray([0xb8,0xe6,0x02,12,0x00,0x01,0x00,0x00,0x00,0x00,0xd2,0xc3])
         #  0xb8 0xe6    0x02  12  0x00 0x00   0x00 0x00  0x00 0x00  0xd2 0xc3
        #格式 2           1     1        2        2       2      2
            #帧头        类型  协议长度  x线速度  y线速度 角速度      帧尾
        self.ser.write(data)
if __name__== "__main__":
    teleop()