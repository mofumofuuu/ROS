#include <cstdlib>
#include "ros/ros.h"
#include "learning_communication/AddTwolnts.h"

int main(int argc,char ** argv)
{
    //ros 初始化
    ros::init(argc,argv,"add_two_ints_client");
    // 从终端命令行获取两个加数
    if(argc != 3)
    {
        ROS_INFO("usage: add_two_ints_client X,Y");
        return 1;
    }
    // 创建 ros句柄
    ros::NodeHandle n;
    //创建一个client，请求add_two_int service ,service消息类型是learning_communication::AddTwoInts
    ros::ServiceClient client = n.serviceClient<learning_communication::AddTwolnts>("add_two_ints");
    // 创建learning_communication::AddTwoInts类型的service消息
    learning_communication::AddTwolnts srv;
    srv.request.a = atoll(argv[1]);
    srv.request.b = atoll(argv[2]);
    // 发布service请求，等待加法运算的结果
    if(client.call(srv))
    {
        ROS_INFO("Sum %ld",(long int )srv.response.sum);
    }
    else
    {
        ROS_ERROR("Falied to call service add_two_ints");
        return 1;
    }
    return 0; 
}