#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <cstring>
int main()
{  
// 串口 8/10 
  const char* portname = "/dev/ttyAMA0";
  int fd = open(portname,O_RDWR);
  if (fd == -1)
  {
	std::cerr << "Error opening" << portname << std::endl;
	return 1;	
  }
  // 配置串口
  struct termios options;
  tcgetattr(fd,&options);
  cfsetispeed(&options,B115200);
  cfsetospeed(&options,B115200);

  options.c_cflag &= ~PARENB; //无奇偶检验
  options.c_cflag &= ~CSTOPB;
  options.c_cflag &= ~CSIZE; 
  options.c_cflag |= ~CS8;

  options.c_cflag |= (CLOCAL | CREAD);

  options.c_lflag &= ~ICANON;
  options.c_lflag &= ~ECHO;
  options.c_lflag &= ~ECHOE;
  options.c_lflag &= ~ECHONL;
  options.c_lflag &= ~ISIG;

 
  tcsetattr(fd,TCSANOW, &options);
  

  // 发送数据
  const char * mes = "1234";
   write(fd,mes,strlen(mes));
  // 读取数据
  char buf[256];
  int n = read(fd,buf,sizeof(buf)-2);
  if(n >0)
  {
  buf[n] = '\0';
  std::cout << "Reseive:" << buf << std::endl;

   }
   close (fd);
   return 0;
}
