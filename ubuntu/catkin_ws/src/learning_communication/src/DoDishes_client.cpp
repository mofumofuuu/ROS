#include <actionlib/client/simple_action_client.h>
#include "learning_communication/DoDishesAction.h"
#include <ros/ros.h>
typedef actionlib::SimpleActionClient<learning_communication::DoDishesAction> Client;
//action 完成后调用该回调函数

void doneCb(const actionlib::SimpleClientGoalState& state,
            const learning_communication::DoDishesResultConstPtr& result)
{
    ROS_INFO("Yay! The dishes are now clean");
    ros::shutdown();
}

//action开始后会调用该回调函数

void activeCb()
{
    ROS_INFO("Goal just went active");
}

// 收到feedback后调用该回调函数
void feedbackCb(const learning_communication::DoDishesFeedbackConstPtr& feedback)
{
    ROS_INFO("percent_complete :%f",feedback->percent_complete);
}

int main(int argc,char ** argv)
{
    ros::init(argc,argv ,"do_dishes_client");
    
    //定义一个客户端
    Client client("do_dishes",true);

    // 等待服务器端
    ROS_INFO("Waiting for action server to start");
    client.waitForServer();
    ROS_INFO("Action server started, sending goal");
    
    // 创建一个action 的goal
    learning_communication::DoDishesGoal goal;
    goal.diswasher_id = 1;

    // 发送action的goal给服务器端，并且设置回调函数
    client.sendGoal(goal,&doneCb,&activeCb,&feedbackCb);
    ros::spin();
    return 0;
}