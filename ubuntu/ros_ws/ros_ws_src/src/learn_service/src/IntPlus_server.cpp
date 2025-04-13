/**
* 该例程将执行/Two_Int_Plus服务，服务数据类型learn_service::IntPlus
*/
#include <ros/ros.h>
#include "learn_service/IntPlus.h"
// service回调函数，输入参数req，输出参数res
bool IntPlusCallback(learn_service::IntPlus::Request &req,learn_service::IntPlus::Response &res)
{
    ROS_INFO("number 1 is:%d ,number 2 is:%d ", req.a, req.b);// 显示请求数据
    res.result = req.a + req.b ;// 反馈结果为两数之和
    return res.result;
}
int main(int argc, char **argv)
{
    ros::init(argc, argv, "IntPlus_server"); // ROS节点初始化
    ros::NodeHandle n;// 创建节点句柄
    // 创建一个server，注册回调函数IntPlusCallback
    ros::ServiceServer Int_Plus_service = n.advertiseService("/Two_Int_Plus",IntPlusCallback);
    // 循环等待回调函数
    ROS_INFO("Ready to caculate.");
    ros::spin();
    return 0;
}
