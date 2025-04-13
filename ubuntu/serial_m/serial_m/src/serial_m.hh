#ifndef __SERIAL_H
#define __SERIAL_H

#include <wiringPi.h>
#include <wiringSerial.h>
#include <stdio.h>
#include <string.h>
#include "m_type.h"

class serial_m{
public:
    serial_m() = default;
    serial_m(int SerialNum, int BoSpeed);
    ~serial_m();

    bool isSerialAvilble();

    void SendBuf();
    void SendAPacket(uint8_t* params, int len);
    void SendBufWithLen();
   
    void PutFloatIntoSendBuf(float data);
    
    void PutInt16IntoSendBuf(int16_t* data);
    void PutInt32IntoSendBuf(int* data);
    void PutCharIntoSendBuf(char* data);
    void PutCharArrayIntoSendBuf(char* dataArray, int len);

    int Recv(int type); // 类型接收 ： 1为接收来自飞控的数据 2为接收来自上位机指令数据 ...

    char* _recvBuf;
    char* _sendBuf;
    int fd;
    int nowIdx_send = 0;
};

void sendAPacket(int fd, uint8_t* params, int len);
int serial_init(int ComNum, int BoSpeed);

#endif 
