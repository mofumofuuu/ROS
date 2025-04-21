// #include <iostream>     // 标准输入输出流库
// #include <fcntl.h>      // 文件控制选项（如O_RDWR）
// #include <unistd.h>     // POSIX操作系统API（如open/read/write）
// #include <termios.h>    // 终端I/O控制（串口配置）
// #include <cstring>      // 字符串处理函数（如strlen）

// using namespace std;

// int main() {
//     // 定义串口设备路径（树莓派常用UART设备）
//     const char* portname = "/dev/ttyAMA0";
//     // 以读写模式打开串口设备，获取文件描述符
//     int fd = open(portname, O_RDWR | O_NOCTTY | O_NDELAY);
//     if (fd == -1) { // 检查是否打开失败
//         std::cerr << "Error opening " << portname << std::endl;
//         return 1;
//     }

//     // 配置串口参数
//     struct termios options;
//     tcgetattr(fd, &options); // 获取当前串口配置

//     // 设置波特率为115200
//     cfsetispeed(&options, B9600); // 输入波特率
//     cfsetospeed(&options, B9600); // 输出波特率

//     // 数据位、校验位、停止位配置
//     options.c_cflag &= ~PARENB;  // 关闭奇偶校验
//     options.c_cflag &= ~CSTOPB;  // 设置1个停止位（若设为1则启用2个停止位）
//     options.c_cflag &= ~CSIZE;   // 清除数据位掩码
//     options.c_cflag |= CS8;      // 设置8位数据位（原代码错误：误用~CS8）

//     options.c_cflag |= (CLOCAL | CREAD); // 忽略调制解调器状态，启用接收

//     // 本地模式配置（原始数据模式）
//     options.c_lflag &= ~ICANON; // 禁用规范模式（直接读原始数据）
//     options.c_lflag &= ~ECHO;   // 关闭回显输入字符
//     options.c_lflag &= ~ECHOE;  // 关闭回显擦除字符
//     options.c_lflag &= ~ECHONL; // 关闭回显换行
//     options.c_lflag &= ~ISIG;   // 禁用信号（如Ctrl+C）

//     // 应用配置（TCSANOW表示立即生效）
//     if (tcsetattr(fd, TCSANOW, &options) != 0) {
//         std::cerr << "Error setting serial port attributes" << std::endl;
//         return 1;
//     }

//     // 发送数据
//     const char* mes = "1234";
//     ssize_t bytes_written = write(fd, mes, strlen(mes));
//     if (bytes_written < 0) {
//         std::cerr << "Write error" << std::endl;
//     }

//     // 读取数据
//     char buf[256];
//     int n = read(fd, buf, sizeof(buf) - 1); // 留一位给终止符
//     if (n > 0) {
//         buf[n] = '\0'; // 添加字符串终止符
//         std::cout << "Received: " << buf << std::endl;
//     } else if (n == 0) {
//         std::cout << "No data received" << std::endl;
//     } else {
//         std::cerr << "Read error" << std::endl;
//     }

//     close(fd); // 关闭文件描述符
//     return 0;
// }

#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <cstring>
#include <cstdint>

//全部采用小端
// 数据包结构定义（与STM32对齐）
#pragma pack(push, 1) // 关闭内存对齐
struct RobotDataPacket {
    uint8_t header = 0xFF;
    int8_t RL_speed;
    int8_t RR_speed;
    uint32_t RL_step;
    uint32_t RR_step;
    float Rangle;
    uint8_t footer = 0xFE;
};
#pragma pack(pop)

// 控制指令结构定义
struct ControlPacket {
    uint8_t header = 0xFF;
    uint8_t SL_speed;
    uint8_t SR_speed;
    uint8_t S_speed;
    uint8_t S_angle;
    uint8_t footer = 0xFE;
};

int main() {
    // 打开串口设备（根据实际设备修改）
    const char* portname = "/dev/ttyUSB0";
    int fd = open(portname, O_RDWR | O_NOCTTY);
    if (fd == -1) {
        std::cerr << "Error opening " << portname << std::endl;
        return 1;
    }

    // 配置串口参数
    struct termios options;
    tcgetattr(fd, &options);
    cfsetispeed(&options, B9600);
    cfsetospeed(&options, B9600);

    options.c_cflag &= ~PARENB;   // 无奇偶校验
    options.c_cflag &= ~CSTOPB;   // 1位停止位
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;       // 8位数据位
    options.c_cflag |= (CLOCAL | CREAD);

    options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG); // 原始模式
    options.c_iflag &= ~(IXON | IXOFF | IXANY);         // 禁用流控
    options.c_oflag &= ~OPOST;                          // 原始输出

    if (tcsetattr(fd, TCSANOW, &options) != 0) {
        std::cerr << "Error setting serial attributes" << std::endl;
        close(fd);
        return 1;
    }

    // 发送控制指令示例
    ControlPacket ctrl_pkt;
    ctrl_pkt.SL_speed = 30;    // 左轮速度
    ctrl_pkt.SR_speed = 30;    // 右轮速度
    ctrl_pkt.S_speed = 50;     // 总体速度
    ctrl_pkt.S_angle = 90;     // 目标角度
    
    if (write(fd, &ctrl_pkt, sizeof(ctrl_pkt)) < 0) {
        std::cerr << "Write control packet failed" << std::endl;
    }


    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // 接收数据循环
    uint32_t swap_endian(uint32_t val) {
        return (val << 24) | ((val << 8) & 0xFF0000) | 
               ((val >> 8) & 0xFF00) | (val >> 24);
    }
    RobotDataPacket rx_pkt;
    uint8_t* pbuf = reinterpret_cast<uint8_t*>(&rx_pkt);
    size_t bytes_expected = sizeof(RobotDataPacket);
    ssize_t bytes_read = 0;

    while (true) {
        // 分字节读取（实际应用中建议用缓冲队列）
        ssize_t n = read(fd, pbuf + bytes_read, bytes_expected - bytes_read);
        if (n < 0) {
            std::cerr << "Read error" << std::endl;
            break;
        }
        bytes_read += n;

        // 完整包接收检测
        if (bytes_read >= sizeof(RobotDataPacket)) {
            // 验证包头包尾
            if (rx_pkt.header == 0xFF && rx_pkt.footer == 0xFE) {
                // 打印数据（注意字节序转换）
                std::cout << "Speed L/R: " 
                          << static_cast<int>(rx_pkt.RL_speed) << "/"
                          << static_cast<int>(rx_pkt.RR_speed) << "\n"
                          << "Steps L/R: "
                          << rx_pkt.RL_step << "/" << rx_pkt.RR_step << "\n"
                          << "Angle: " << rx_pkt.Rangle << "°\n"
                          << std::endl;
            } else {
                std::cerr << "Invalid packet format" << std::endl;
            }
            bytes_read = 0; // 重置计数器
        }
    }

    close(fd);
    return 0;
}
