#include <sstream>
#include "ros/ros.h"
#include "std_msgs/String.h"
int main(int argc,char **argv)
{
    //初始化结点
    ros::init(argc,argv,"talker");// 只是作为一个结点，是ros的最小进程单位
    // 创建节点句柄
    ros::NodeHandle n; //很多与ros系统的操作都需要借助这个变量的函数去进行
    // 创建一个Publisher，发布名
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter",1000);

    //设置循环的频率
    ros::Rate loop_rate(10);
    int count = 0;
    while(ros::ok())
    {
        //初始化std_msgs::String类型的消息
        std_msgs::String msg;
        std::stringstream ss;
        ss << "hello ROS" << count;
        msg.data = ss.str();
        //发布消息
        ROS_INFO("%s",msg.data.c_str());
        chatter_pub.publish(msg);
        // 循环等待回调函数
        ros::spinOnce();
        loop_rate.sleep();
        ++count;
    }
    return 0;
}