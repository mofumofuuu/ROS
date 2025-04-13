
# 编译器设置
CC = g++
CFLAGS = -Wall -Wextra  -lwiringPi -lbcm2835  
LDFLAGS = -lwiringPi -lbcm2835  -lm -lpthread -lrt -lcrypt

# 源文件和目标文件设置
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# 源文件和目标文件列表
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))
EXECUTABLE = serial

# 默认目标
all: $(EXECUTABLE)

# 生成可执行文件
$(EXECUTABLE): $(OBJECTS)
	$(CC) $^ -o $@ $(LDFLAGS)

# 生成目标文件
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@ 

# 清理编译生成的文件
clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all clean
