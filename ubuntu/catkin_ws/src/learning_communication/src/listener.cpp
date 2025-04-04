#include "ros/ros.h"
#include  "std_msgs/String.h"

// 订阅chatter话题。消息类型String
// 接受到订阅的消息后，进入消息回调函数
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
    //将接受到的消息打印出来
    ROS_INFO("I heard: [%s]", msg->data.c_str());

}
int main(int argc,char ** argv)
{
    // 初始化ROS节点
    ros::init(argc,argv,"listener");
    // 创建节点句柄
    ros::NodeHandle n;
    //创建一个 Subscriber，订阅名位chatter的topic，注册回调函数chatterCallback
    ros::Subscriber sub= n.subscribe("chatter",1000,chatterCallback);
                                 //    话题名   队列   注册回调函数
    // 循环等待回调函数
    ros::spin();
    return 0;
}