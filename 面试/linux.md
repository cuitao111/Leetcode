# 参考书籍
《UNIX环境高级编程》
《Linux/UNIX系统编程手册》
《Linux内核设计与实践》
《计算机网络 第7版》
《TCP/IP详解 卷1》
《UNIX网络编程 第3版》

# 为什么学习这门课

1. 进程间通信方式
2. 僵尸进程，孤儿进程
3. 线程同步怎么解决
4. 大端和小端的区别
5. IO多路复用有哪些方式？区别
6. 静态库和动态库的制作以及使用
7. 滑动窗口的机制
8. TCP三次握手和四次挥手
9. TCP和UDP的区别


# Linux系统编程入门、

## 1.2 GCC
GNU Compiler Collection 支持C C++ Object——C Java Ada Go
也包括了这些语言的库（什么意思） libstdc++ libgcj

可以区别不同的c语言标准 C89 C99 GNU99
可以使用命令行选项来控制编译器在翻译原代码时时用那个标准  '-std=c99'  >4.8.5 支持c++11版本的一些特性

gcc test.c -o app 
'-o' 指定要生成的目标的名称 默认a.out

高级语言 -》汇编 -》 机器 -》计算机
比如你用8086汇编，汇编器看到你文本里写个nop，它就在二进制的目标文件里填个0x90

### GCC工作流程
源代码 -》预处理器-》预处理后的源代码（.i）-》编译器-》汇编代码(.s)->汇编器-》目标代码(.o 二进制代码) -》链接-》可执行代码（.exe .out）

预处理过程：头文件替换 删除注释 宏替换

链接的过程要结合启动代码，库代码，其他目标代码

gcc test.c -E -o test.i
-E :预处理不编译

gcc test.i -S -o test.s
-S:编译不汇编

gcc test.s -c -o test.o
-c 编译、汇编不链接

-o file1 file2
file2 -o file1
将file2编译成可执行文件file1

-I directory 指定include包含文件的搜索目录

-g 编译时生成调试信息

-D 在程序编译的时候，指定一个宏
gcc -c test.c -o test -DDEBUG
相当于 #define DEBUG
#ifdef DEBUG
    printf("Log 信息");
#endif

-W 不生成任何警告信息

后缀为c的代码 gcc把他当作C程序 而g++ 当作是c++程序
后缀为CPP 都当作c++程序
编译阶段g++会调用gcc 对于c++代码两者是等价的但gcc不能自动和c++程序使用的库链接，所以通常用g++ 完成链接，为了统一干脆全用g++

编译可用gcc/g++ 链接可用 g++ 或者 gcc - lstdc++ 
-l std c++ :链接 标准 c++

### 1.4 静态库
动静态库的区别
库的好处 1代码保密 2方便部署和分发

### 静态库命名规则：
Linux: libxxx.a
lib:前缀（固定）
xxx：库名
.a: 后缀（固定）

Win：libxxx.lib

### 静态库的制作：

gcc编译获得.o文件
将.o文件打包，使用ar工具(archive)
ar rcs libxxx.a xxx.o xxx.o
r - 将文件插入备存文件中 插入库文件中
c - 建立备存文件
s - 索引 方便查找

### 1.5静态库的使用

————include
    |____head.h
————main.c
————lib
    |___libcalc.a

gcc main.c -o app -I ./include/ -l calc -L./lib
到include中找头文件
-l - 指定库名字 -L 库目录

### 1.6 动态库(共享库)的制作和使用

Linux: libxxx.so
    lib:固定
    xxx：
    .so: 固定
    在linux下是一个可执行文件
Win:libxxx.dll

### 制作
gcc编译得到.o文件，得到和位置无关的代码
gcc -c -fpic/-fPIC a.c b.c
gcc 得到动态库
gcc -shared a.o b.o -o libcalc.so

### 使用
————include
    |____head.h
————main.c
————lib
    |___libcalc.so

gcc main.c -o app -I include/ -l calc -L./lib
此时不能运行main

-I 头文件目录 -l 库名 -L 库目录

ldd main
ldd命令：检查动态库的依赖关系
系统加载可执行代码时，能够直到其所依赖的库的名字，但还是需要知道绝对路径。此时就需要系统的动态载入器(ld-linux-x86-64.so.2)来获取绝对路径。 
对于elf格式的可执行程序，是由ld-linux.so来完成的，它先后搜索elf文件的DT_RPATH段——》环境变量LD_LIBRARY_PATH--> /etc/ld.so.cache文件列表 --》/lib/ , /usr/lib目录找到库文件后将其载入内存

DT_RPATH段：可执行文件运行起来就是一个进程，LInux系统会为每个进程分配一个虚拟地址空间，DT_RPATH段就在这个虚拟的地址空间中，如果没有把动态库的路径放入找不到，该段内容无法更改

当调用了动态库的API之后，动态载入器在绝对路径中根据库名找库加载到内存中

临时：export LD_LIBRARY_PATH=$LD_LIBRARY:/home/lib/path
用户级别的配置：~/.bashrc  . .bashrc
系统级别：/etc/profile source /etc/profile （root权限)

配置 /etc/ld.so.cache
不能直接修改 间接：sudo vim /etc/ld.so.conf
粘贴绝对路径
更新 sudo ldconfig

不建议放在 /lib/ /usr/lib 命名冲突导致系统库出问题

### 1.9 静态库和动态库的对比
静态库在链接过程中会直接打包到可执行文件中，可执行程序中会包含静态库的代码
动态库链接过程中只会打包一些动态库的信息，如动态库的名字，可执行程序在运行时需要找到动态库的路径加载到内存中


动态库汇编需要加 -fpic 链接不需要用ar 用gcc -shared 

为什么要加-fpic 
加载静态库是直接打包，代码位置是固定的，只要知道主程序入口位置，在内存位置也是固定
而动态库不知道什么时候调用，在内存的位置也不固定，因此需要打包成与位置无关的二进制代码

__与位置有关的代码？__


### 使用场景
库较小使用静态库

### 优缺点

静 优点：
静态库打包到应用程序中加载速度块
发布程序无需提供静态库，移植方便(给用户提供exe文件时无需提供lib)
缺点：
消耗系统资源，浪费内存（内存中存在多个重复库文件）
更新、部署、发布麻烦（更新库文件之后，需要重新编译所有调用库的代码）
动 优点：
可以实现进程间资源共享（共享库）
更新、部署、发布简单（只需编译 生成库文件） 动态库的API改变
可以控制何时加载动态库（）
缺点：
加载速度比静态库
发布程序时需要提供依赖的动态库

速度 更新 发布是否提供 内存

### 1.10 Makefile

工程中 源文件按类型功能模块分别放在若干个目录中，方便管理
inclue src

Makefile 定义了一个规则来指定哪些文件需要先编译，哪些文件需要后边编译，哪些需要重新编译，甚至于更复杂的功能操作，因为Makefile文件就像一个Shell脚本一样可以执行操作系统的命令。
“自动化编译”，一旦写好，只需要一个make命令，整个工程完全自动编译，极大地提高了软件开发的效率。 
make是一个解释Makefile文件中指令的命令工具，
如Delphi的make Visual C++的nmake Linux下GNU的make
 








# Linux多进程开发

# Linux多线程开发

# Linux网络编程

# 项目实战