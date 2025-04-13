#include "serial_m.hh"
#include <iostream>
#include <mutex>
#include <thread>
#include <iomanip>
#include <unistd.h>

using namespace std;

extern float dis;
extern float speed;
//发送数据
// struct PoseData{
//     struct translation{
//         float x,y,z;
//     }translation;
//     struct Rotation{
//         float w,x,y,z;
//     }rotation;
//     void print() const {
//         std::cout << "Position: (" << translation.x << ", " << translation.y << ", " << translation.z << ") "
//                   << "Rotation: (" << rotation.w << ", " << rotation.x << ", " << rotation.y << ", " << rotation.z << ")\n";
//     }
// };

// PoseData getPoseData()
// {
//     PoseData pose;
//     pose.translation.x =1.23f;
//     pose.translation.y =4.56f;
//     pose.translation.z = 7.89f;
    
//     pose.rotation.w = 0.707f;
//     pose.rotation.x = 0.0f;
//     pose.rotation.y = 0.707f;
//     pose.rotation.z = 0.0f;
//     return pose;
// }


 

int main() try
{
    // ********************** T265 初始化 **********************************
    std::string serial;
    // ********************** 初始化wiringPI************************
    if (wiringPiSetup() == -1)
    {
        printf("setup wiringPi failed !");
        return -1;
    }
    // ********************** 超声波初始化 *****************************
   //  ultraInit();
    // ***********************  串口初始化 **************************
    // 飞控串口
    serial_m PI_serial(0, 115200);

    if(!PI_serial.isSerialAvilble()){
       cout<<"The 32 Serial init Failed!"<<endl;
       return -1;
    }
    
    while (true)
    {
    //    PoseData pose = getPoseData();
    //    pose.print();
       

      
        // PI_serial.PutFloatIntoSendBuf(pose.translation.x);   // 前4位为vx
        // PI_serial.PutFloatIntoSendBuf(pose.translation.y);  
        // PI_serial.PutFloatIntoSendBuf(pose.translation.y);
        // PI_serial.PutFloatIntoSendBuf(pose.rotation.z);
        // uint8_t data[]={0x11,0x12,0x13,0x14};
        uint8_t data[]={0x11};
        //printf("%d",sizeof(data));
       PI_serial.SendAPacket(data,sizeof(data));
       //PI_serial.SendAPacket(data,sizeof(data));
      break;
       //usleep(1000);
        //fly_serial.PutFloatIntoSendBuf(dis);
        //fly_serial.PutFloatIntoSendBuf(vy);
        // 发送
      
        // 接收
        //int recvLen = fly_serial.Recv(1);
        // ******************** 上位机 串口处理 ************************
        //air_serial.PutFloatIntoSendBuf(vx);   // 前4位为vx
       // air_serial.PutFloatIntoSendBuf(vz);  
      //  air_serial.PutFloatIntoSendBuf(x);
       // air_serial.PutFloatIntoSendBuf(z);
        //  air_serial.PutFloatIntoSendBuf(dis);
        //  air_serial.PutFloatIntoSendBuf(vy);
        //if(recvLen > 0){
          //  air_serial.PutCharArrayIntoSendBuf(fly_serial._recvBuf + 1, recvLen - 1);
       // }
        //air_serial.SendBufWithLen();
       // usleep(10);
    }
}

catch (const std::exception& e)
{
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
}

