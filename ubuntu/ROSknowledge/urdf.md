# 创建urdf文件

找好地址 使用roslaunch urdf_tutorial display.launch model:=visual.urdf

## 内容

- 圆柱 
```
<visual>
<geometry>
    <cylinder radius="0.5" length="0.1"/>
    </geometry>
</visual>
```
- box
```
<geometry>

<box size = "1 1 1"/>
</geometry>
```
- 球
```
<geometry>
    <sphere radius="0.5" />
    </geometry>
``` 
- joint  (type contious  fixed )
```
- parent
- child
- <origin xyz="0 0 0.6"  rpy="1.5705 0 0"/>  // 父与子的相对关系  绕谁转谁设值
```

## 无法显示continuous的link

    sudo apt install ros-melonic-joint-state-publisher-gui

```
<robot name="my_robot">
    <link name = "base_footprint">
        <visual>
        <geometry>
           
            <sphere radius="0.01"/>
        </geometry>
        </visual>
        </link>
    <link name = "base_link">
        <visual>
            <geometry>
                <box size ="0.3 0.18 0.02" />
            </geometry>
            <origin xyz="0 0 0" rpy="0 0 0"/>
                <material name = "yellow">
                <color rgba="1 1 0 1" />
                </material>
        </visual>
      
        </link>    
    <joint name = "base_link2base_footprint" type="fixed">
        <parent link = "base_footprint"/>
        <child link= "base_link"/>
        <origin xyz="0 0 0.06"/>

    </joint>
    <!-- 左下-->
    <link name="a_wheel">
        <visual>
            <geometry>
                <cylinder radius="0.04" length="0.035"/>
            </geometry>
            <origin xyz="0 0 0" rpy="1.5705 0 0"/>
            <material name ="black">
                <color rgba ="0 0 0 1"/>
            </material>
        </visual>
    </link>


    <joint name="a_wheel2base_link" type ="continuous">
        <parent link="base_link"/>
        <child link="a_wheel"/>
        <origin xyz="-0.1 0.11 -0.02"/>
        <axis xyz="0 0 1"/>
    </joint>

    <!-- 左上-->
    <link name="b_wheel">
        <visual>
            <geometry>
                <cylinder radius="0.04" length="0.035"/>
            </geometry>
            <origin xyz="0 0 0" rpy="1.5705 0 0"/>
            <material name ="black">
                <color rgba ="0 0 0 1"/>
            </material>
        </visual>
    </link>


    <joint name="b_wheel2base_link" type ="continuous">
        <parent link="base_link"/>
        <child link="b_wheel"/>
        <origin xyz="0.1 0.11 -0.02"/>
        <axis xyz="0 0 1"/>
    </joint>


    <!-- 右上-->
    <link name="c_wheel">
        <visual>
            <geometry>
                <cylinder radius="0.04" length="0.035"/>
            </geometry>
            <origin xyz="0 0 0" rpy="1.5705 0 0"/>
            <material name ="black">
                <color rgba ="0 0 0 1"/>
            </material>
        </visual>
    </link>


    <joint name="c_wheel2base_link" type ="continuous">
        <parent link="base_link"/>
        <child link="c_wheel"/>
        <origin xyz="0.1 -0.11 -0.02"/>
        <axis xyz="0 0 1"/>
    </joint>

    <!-- 右下-->
    <link name="d_wheel">
        <visual>
            <geometry>
                <cylinder radius="0.04" length="0.035"/>
            </geometry>
            <origin xyz="0 0 0" rpy="1.5705 0 0"/>
            <material name ="black">
                <color rgba ="0 0 0 1"/>
            </material>
        </visual>
    </link>


    <joint name="d_wheel2base_link" type ="continuous">
        <parent link="base_link"/>
        <child link="d_wheel"/>
        <origin xyz="-0.1 -0.11 -0.02"/>
        <axis xyz="0 0 1"/>
    </joint>


    </robot>
```



