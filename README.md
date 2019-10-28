# DataStructure

【可信软件能力认证培训】基础算法和数据结构
LeetCode题解，151道题完整版：https://github.com/soulmachine/leetcode

Acm Cheat Sheet（手写代码必备手册）：https://github.com/soulmachine/acm-cheat-sheet

动态规划讲解：

https://www.jianshu.com/p/919cd4e268b1

https://blog.csdn.net/sinat_38816924/article/details/82982865

https://m.sohu.com/a/153858619_466939/?pvid=000115_3w_a&strategyid=00014

贪心算法讲解：https://www.jianshu.com/p/b613ae9d77ff

红黑树：https://github.com/julycoding/The-Art-Of-Programming-By-July/blob/master/ebook/zh/03.01.md



#source file


#源文件，自动找所有.c和.cpp文件，并将目标定义为同名.o文件

SOURCE  := $(wildcard *.c) $(wildcard *.cpp)
OBJS    := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))


#target you can change test to what you want


#目标文件名，输入任意你想要的执行文件名

TARGET  := main


#compile and lib parameter


#编译参数

CC      := g++
LIBS    :=
LDFLAGS :=
DEFINES :=
INCLUDE := -I.
CFLAGS  := -g -Wall -std=c++11 -O3 $(DEFINES) $(INCLUDE)
CXXFLAGS:= $(CFLAGS) -DHAVE_CONFIG_H



#i think you should do anything here


#下面的基本上不需要做任何改动了

.PHONY : everything objs clean veryclean rebuild

everything : $(TARGET)

all : $(TARGET)

objs : $(OBJS)

rebuild: veryclean everything

clean :
    rm -fr *.so
    rm -fr *.o

veryclean : clean
    rm -fr $(TARGET)

$(TARGET) : $(OBJS)
    $(CC) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(LIBS)
