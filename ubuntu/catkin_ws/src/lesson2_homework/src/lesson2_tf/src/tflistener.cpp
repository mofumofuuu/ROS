#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/TransformStamped.h>

int main(int argc,char ** argv)
{
    ros::init(argc,argv,"tf_listener");
    ros::NodeHandle nh;

    // 创建tf监听
    tf::TransformListener listener;

    ros::Rate rate(10.0);

    while(ros::ok())
    {
        try
        {
            // 获取从base_link 到 camera_link 的变换
            tf::StampedTransform transform;
            listener.lookupTransform("base_link","camera_link",ros::Time(0),transform);

            ROS_INFO("translation: [%.2f, %.2f, %.2f] Rotation: [%.2f ,%.2f, %.2f,%.2f]",
            transform.getOrigin().x(),transform.getOrigin().y(),transform.getOrigin().z(),
            transform.getRotation().x(),transform.getRotation().y(),transform.getRotation().z(),
            transform.getRotation().w());
        }
        catch (tf::TransformException &ex)
        {
            ROS_WARN("%s",ex.what());
            ros::Duration(1.0).sleep();
        }
        rate.sleep();
    }
    return 0;
}