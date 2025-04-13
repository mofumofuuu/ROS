#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include "learning_communication/DoDishesAction.h"

typedef actionlib::SimpleActionServer<learning_communication::DoDishesAction> Server;

// 收到action的goal后调用该回调函数

void execute(const learning_communication::DoDishesGoalConstPtr& goal,Server* as)
{
    // 按照1hz的频率发布
    ros::Rate r(1);
    //定义回复
    learning_communication::DoDishesFeedback feedback;
    ROS_INFO("Dishwasher %d is working",goal->diswasher_id);

    // 假设洗盘子的进度，并且按照1hz的频率发布进度feedback
    for (int i = 1; i<= 10 ; i++)
    {
        feedback.percent_complete = i * 10;
        as->publishFeedback(feedback);
        r.sleep();
    }
    // 当action 借助话题发布去执行 完成之后，向客户端返回结果

    ROS_INFO("Dishwasher %d finish working." ,goal->diswasher_id);
    as-> setSucceeded();
}
int main(int argc ,char ** argv)
{
    ros::init(argc,argv,"do_dishes_server");
    ros::NodeHandle n;
    //定义一个服务器                        回调函数  第一个参数  第二个参数
    // 绑定为动作库的回调函数                        _1占位符指的是第一个参数 false 表示是否自动启动
    Server server(n,"do_dishes",boost::bind(&execute,_1,&server),false);
    server.start();
    ros::spin();//循环执行
    return 0;
}                                 