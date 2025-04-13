#include "serial_m.hh"

serial_m::serial_m(int SerialNum, int BoSpeed){
    char buf[32]={0};
    sprintf(buf, "/dev/ttyAMA%d", SerialNum);
    fd = serialOpen(buf, BoSpeed);
    if(-1 == fd){
        printf("open failed!\n");
    }

    // 初始化缓冲区
    _sendBuf = new char[512];
    _recvBuf = new char[512];
    memset(_sendBuf, 0, 512);
    memset(_recvBuf, 0, 512);
}

serial_m::~serial_m(){
    serialClose(this->fd);
    delete _sendBuf;
    delete _recvBuf;
}

bool serial_m::isSerialAvilble(){
    if(fd == -1) return false;
    else return true;
}

void serial_m::SendBuf(){
    if(-1 == this->fd){
        printf("fd == -1\n");
        return;
    }
    serialPutchar(fd, 0xFF);
    for(size_t i = 0;i<strlen(this->_sendBuf);i++){
        serialPutchar(fd, this->_sendBuf[i]);
        printf("%x ", _sendBuf[i]);
    }
    printf("\n");
    serialPutchar(fd, 0xFE);

    // 清空发送缓冲区
    this->nowIdx_send = 0;
    memset(this->_sendBuf, 0, 512);
}

void serial_m::PutFloatIntoSendBuf(float data){
    // printf("%.3f\n ", data);
    for(int i = nowIdx_send ;i< nowIdx_send + 4; i++){
        _sendBuf[i] = ((unsigned char *)&data)[i - nowIdx_send];
    }
    nowIdx_send += 4;
}

void serial_m::PutInt32IntoSendBuf(int* data){
    for(int i = nowIdx_send ;i< nowIdx_send + 4; i++){
        _sendBuf[i] = ((unsigned char *)data)[i - nowIdx_send];
    }
    nowIdx_send += 4;
}


void serial_m::PutInt16IntoSendBuf(int16_t* data){
    for(int i = nowIdx_send ;i< nowIdx_send + 2; i++){
        _sendBuf[i] = ((unsigned char *)data)[i - nowIdx_send];
    }
    nowIdx_send += 2;
}

void serial_m::PutCharIntoSendBuf(char* data){
    for(int i = nowIdx_send ;i< nowIdx_send + 1; i++){
        _sendBuf[i] = ((unsigned char *)data)[i - nowIdx_send];
    }
    nowIdx_send += 1;
}

void serial_m::PutCharArrayIntoSendBuf(char* data, int len){
    for(int i = nowIdx_send ;i< nowIdx_send + len; i++){
        _sendBuf[i] = data[i - nowIdx_send];
    }
    nowIdx_send += len;
}


int serial_m::Recv(int type){
    int RecvStatus = 0;
    int recvLen = 0;
    int nowDataIdx = 0;
    switch (type)
    {
    case 1:
        while(serialDataAvail(fd) > 0){
            uint8_t by = serialGetchar(fd);
            switch (RecvStatus)
            {
            case 0:
                if (by == 0xff){
                    RecvStatus = 1;
                }
                break;
            case 1:
                recvLen = by;
                _recvBuf[nowDataIdx] = recvLen + 14;
                nowDataIdx++;
                RecvStatus = 2;
                break;
            case 2:
                _recvBuf[nowDataIdx] = by;
                nowDataIdx++;
                if (nowDataIdx >= recvLen + 1)
                {
                    RecvStatus = 3;
                }
                break;
            case 3:
                if (by == 0xfe)
                {
                    RecvStatus = 0;
                    return nowDataIdx;
                }
                break;
            }
        }
        break;
    case 2:
      
        break;
    default:
        break;
    }
 
}

void serial_m::SendAPacket(uint8_t* params, int len){
    if(-1 == fd){
        printf("fd == -1\n");
        return;
    }
    serialPutchar(fd, 0xFF);
    for(int i = 0;i<len;i++){
        serialPutchar(fd, params[i]);
         printf("%x ", params[i]);
    }
    // printf("\n");
    serialPutchar(fd, 0xFE);
}

void serial_m::SendBufWithLen(){
    if(-1 == this->fd){
        printf("fd == -1\n");
        return;
    }
    serialPutchar(fd, 0xFF);
    serialPutchar(fd, nowIdx_send);
    printf("%x ", nowIdx_send);
    for(int i = 0;i<static_cast<int>(strlen(this->_sendBuf));i++){
        serialPutchar(fd, this->_sendBuf[i]);
        printf("%x ", _sendBuf[i]);
    }
    printf("\n");
    serialPutchar(fd, 0xFE);

    // 清空发送缓冲区
    this->nowIdx_send = 0;
    memset(this->_sendBuf, 0, 512);
}
