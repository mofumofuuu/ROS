#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>

int main(int argc, char** argv)
{
    ros::init(argc,argv,"tf_braodcast");
    ros::NodeHandle nh;
    //创建 TransformBroadcaster
    tf::TransformBroadcaster br;

    ros::Rate rate(10.0);

    while(ros::ok())
    {
        // 创建 TransformStamped 消息
        geometry_msgs::TransformStamped t;

        // 设置父坐标系和子坐标系

        t.header.stamp = ros::Time::now();
        t.header.frame_id ="base_link";
        t.child_frame_id = "camera_link";

        // 设置平移
        t.transform.translation.x = 1.0;
        t.transform.translation.y = 0.0;
        t.transform.translation.z = 0.0;

        //设置旋转 （欧拉角转四元数）
        tf::Quaternion q;
        q.setRPY(0, 0, 1.57);// 绕z轴旋转90度转为四元数放入q中
        t.transform.rotation.x = q.x();
        t.transform.rotation.y = q.y();
        t.transform.rotation.z = q.z();
        t.transform.rotation.w = q.w();
        br.sendTransform(t);

        rate.sleep();
    }
    return 0;
}