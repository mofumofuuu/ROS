#include "ros/ros.h"
#include "learning_communication/AddTwolnts.h"

bool add(learning_communication::AddTwolnts::Request &req,
learning_communication::AddTwolnts::Response &res)

{
    res.sum = req.a +req.b;
    ROS_INFO("request: x = %ld, y = %ld",(long int) req.a,(long int)req.b);
    ROS_INFO("sending back response: [%ld]",(long int)res.sum);
    return true;
}
int main(int argc,char** argv)
{
    //ros 结点初始化
    ros::init(argc,argv,"add_two_ints_server");
    //创建节点句柄
    ros::NodeHandle n;
    // 创建一个名为add_two_ints的server，回调函数位add()
    ros::ServiceServer service = n.advertiseService("add_two_ints",add);

    // 循环等待回调函数
    ROS_INFO("Ready to add two ints");
    ros::spin();
    return 0;
}