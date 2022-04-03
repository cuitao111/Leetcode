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

目标：看目录能想出命令作用

# Linux系统编程入门、

## 1.2 GCC
GNU Compiler Collection （GNU 编译组件）
 支持C C++ Object——C Java Ada Go
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
 
### 文件命名
makefile 或者 Makefile

### 规则
可以有一个或者多个规则
目标 ...: 依赖 ...
    命令(Shell 命令)、
    ...

目标： 最终要生成的文件（伪目标除外）
依赖： 生成目标所需要的文件或是目标
命令： 通过执行命令对依赖操作生成目标（命令前必须Tab缩进）

vim Makefile

app:sub.c add.c mult.c div.c main.c
    gcc sub.c add.c mult.c -o app

make

方便之处在于当修改的源文件之后，直接执行make就可以

Makefile其他的规则都是为第一条规则服务的
与第一条命令无关的不执行

### 工作原理

在执行命令前，先检查依赖是否存在
    存在则执行，
    不存在，向下检查其他的规则，有没有是生成这个依赖的，找到了，则执行该规则中的命令

app:sub.o add.o mult.o div.o main.o
    gcc sub.o add.o mult.o div.o main.o -o app

sub.o:sub.c
    gcc -c sub.c -o sub.o

add.o:add.c
    gcc -c add.c -o add.o

...

检查更新，在执行规则中的命令时，会比较目标和依赖文件的时间
    依赖比目标时间晚，重新生成目标文件
    依赖时间比目标时间早，目标不需要更新，对应规则中的命令不需要被执行

修改源文件之后重新编译
分开编译 sub.o add.o ... 效率更高，当只修改了sub.c时不需要编译其他.c文件

### 变量

自定义变量： 变量名=变量值
预定义变量：
AR：归档维护程序名称，默认为ar
CC：C编译器名称，默认值为cc
CXX：C++编译器名称，默认值为g++
$@:目标的完整名称
$<：第一个依赖文件名称
$^：所有依赖文件
获取变量的值：
$(CC)

[例] app:main.c a.c b.c
        gcc -c main.c a.c b.c
自动变量只能在规则的命令中使用
app main.c a.c .b.c
    $(CC) -c $^ -o $@

#定义变量
src=sub.o add.o mult.o div.o main.o
target=app
$(target):$(src)
    $(CC) $(src) -o $(target)

### 模式匹配

add.o:add.c
    gcc -c add.c

div.o:div.c
    gcc -c div.c
...

src=sub.o add.o mult.o div.o main.o
target=app
$(target):$(src)
    $(CC) $(src) -o $(target)

%.o:%.c
    $(CC) -c $< -o $@
% - 通配符，匹配一个字符串

执行第一句时发现没有依赖add.o 
向下匹配 %.o 能够匹配上

### 函数
$(wildcard PATTERN)
功能：获取指定目录下指定类型的文件列表
参数：PATTERN指定的是某个或多个目录下对应的某种类型的文件，如果由多个目录，一般使用空格间隔
返回：若干个文件列表，文件名之间用空格间隔

$(wildchard  *.c ./sub/.c)
获取当前目录和 ./sub目录下的.c文件获取
返回值格式：a.c b.c c.c
$(patsubst %.c, %.o, x.c, bar.c)
将x.c和bar.c 匹配%.c 匹配上则替换为%.o
返回x.o bar.o

src=sub.o add.o mult.o div.o main.o

src=$(wildchard ./*.c)
objs=$(patsubst  %.c, %.o, $(src))
target=app
$(target):$(objs)
    $(CC) $(objs) -o $(target)
%.o:%.c
    $(CC) -c $< -o $@

中间会生成很多.o文件
clean:
    rm $(objs) -f

$make clean
tips:如果目录下有clean文件 会提示clean已经是最新
而不是执行rm -f *.o

定义一个伪目标
.PHONY:clean
clean:
    rm $(objs) -f

就不会将依赖与目标文件时间比较

### 1.11 GDB调试

GDB 是由GNU软件系统社区提供的调试工具，同GCC配套组成了一套完整的开发环境，GDB是Linux和许多类Unix系统中的标准开发环境

### GDB功能
1.启动程序，可以按照自定义要求随心所欲运行程序
2.断电调试
3.程序停住时可以检查程序中的变量等情况
4.可以改变程序，将一个bug产生的影星修正而此时其他bug

# 准备工作
关掉编译器优化选项(`-O`)，并打开调试选项（`-g`）
-Wall 在尽量不影响程序行为的情况下选项打开所有warning，可发现许多问题，避免一些不必要的BUG
 -g 选项的作用是在可执行文件中加入源码的信息，比如可执行文件中第几条机器指令对应源码的第几行，方便调试时找到源文件

 ### GDB命令

启动/退出
    gcc test.c -o test -g
    gdb test

    quit/q

设置参数/获取参数：
    set args 10 20

    show args

帮助
    help

查看当前文件代码
    list/l(从默认位置显示)
    list/l 行号（从指定行显示） list/l 20 (把20行作为中间，显示15 -24 )
    list/l 函数名（从指定的函数显示） list main
查看非当前文件代码
    list/l 文件名：行号
    list/l 文件名：函数名 list select.cpp:selectSort
设置显示的行数
    show list/listsize
    set list/listsize 行数

调试时可执行文件和源文件需要放在一起
回车默认使用上一次的命令
vim :set nu

设置断点
    b/break + 行号/函数名/文件名:行号/文件名：函数

查看断点
    i/info b/break

删除断点
    d/del/delete 断点编号

设置断点无效
    dis/disable

设置断点有效
    enable/ena

设置条件断点(一般用在循环位置)
    b/break 10 if i==5

运行GDB程序
    start(程序停在第一行)
    run（遇到断点才停）

继续运行，到下一个断点停
    c/continue

向下执行一行代码（不会进入函数体）
    n/next

变量操作
    p/print 变量名（打印变量值）
    ptype   变量名（打印变量类型）

向下单步调试（遇到函数进入函数体）
    s/step
    finish(跳出函数体) 不能在内部有断点

自动变量操作
    display num（自动打印指定变量的值）
    i/info display
    undisplay 编号

其他操作
    set var 变量名=变量值
    unil（跳出循环） 不能在内部有断点

操作流程：
1.生成可调试的可执行程序
gcc test.c -o test -g
2.启动gdb
gdb test
3.查看代码 设置断点
break main.c:10
4.启动
strat/run  
5.向下运行
continue n/next（跳过） s/step（进入） finish
6.查看变量
p/print ptype  display num

### 1.17 标准C库IO函数和Linux系统IO函数对比

站在内存的角度看IO
输入：文件-》内存
输出：内存-》文件

### C库IO
fopen flose fread fwrite fgets fputs fscanf
fprints fseek fgetc fputs ftell feof fflush

C库IO可以跨平台
跨平台实现方式：
Java 为每个平台都提供了一个虚拟机
第三方库（C库）不属于操作系统的一部分，需要调用不同平台的API来实现输入输出


C库与LinuxIO函数是调用与被调用关系
LinuxIO函数偏底层
C库IO函数效率更高 因为有缓冲区 

[例]fopen 返回值 FILE *fp 
用man 3 fopen查看

FILE * ->结构体
文件描述符（整型值） ：指向一个已经打开的文件 定位文件位置 win称作文件距离 int _fileno
文件读写指针位置：读取数据和写数据 char* _IO_read_ptr char* _IO_write_ptr
I/O缓冲区（内存地址）：默认大小（8192Byte） char* _IO_buf_base
char* _IO_buf_end
cpu向缓冲区读写数据速度要快，向磁盘传送慢
如果每次把数据存到缓冲区，等满后一次性传到磁盘提高效率

何时写：
1.刷新缓冲区 fflush
2.缓冲区已满
3.正常关闭文件
a.fclose b.return(main函数) c.exit(main函数)

 应用场景：
 网络通信：高响应速度 Linux系统I/O
 对磁盘读写时：调高效率 用C库I/O

 FILE指针 /usr/include/x86_64-linux-gnu/bits/types/FILE.h


 ### 1.18虚拟地址空间

可执行程序运行期间会对应一个虚拟地址空间 ，程序结束虚拟地址空间不存在
程序运行起来就是一个进程
进程是系统给程序分配资源的最小单位

程序：磁盘上的代码 
进程：运行当中的程序，会加载到内存中

虚拟地址空间大小由CPU决定 32位电脑 大小为 2^32 (4G)
64位 2^48
[例] 
0~3G用户区   —— 可以让用户自己操作

受保护的地址（0-4k） nullptr
.text (代码段，二进制机器指令)   |ELF格式主要包含三个段
.data(已初始化全局变量)          |
.bss(已初始化全局变量)           |
堆空间 new malloc 创建的 ↑
共享库 动态库存储空间
栈空间  局部变量 ↓
命令行参数 char* argv[]
环境变量 env

3G~4G 内核区 —— 内核空间是受保护的，用户不能对空间进行读写操作，否则会出现段错误，但可以通过API调用
内存管理、进程管理、设备驱动管理、VFS虚拟文件系统
虚拟内存会被CPU的逻辑管理单元MMU映射到真实物理内存中
映射的过程也叫虚拟内存管理技术

### 1.19文件描述符
FILE* 含有一个文件描述符（整型）
是通过调用LInux I/O返回的

程序：代码，不占用内存空间，只占用磁盘空间
进程：可执行程序运行时，操作系统会为程序的运行分配一些资源，创建一个进程，占用内存空间

进程包含虚拟内存？

文件描述符在虚拟内存的内核区，由内核进行管理
内存管理模块有一个PCB进程控制块 来管理文件描述符
Linux内核就是一段程序
操作系统能对整个系统运行进行后台管理，还包括一下系统工具Office，GCC，GDB
PCB是一个非常复杂的结构体，把需要管理的数据都封装到PCB结构体中，在PCB中有一个数组成为文件描述符表
一个进程可以同时打开多个文件，所以要用一个数组来存储
大小默认1024 （默认能够打开1024个文件）

前三个默认使用 0：STDIN——FILENO 标准输入
1：标准输出 STDOUT_FILENO
2：错误 STDERR_FILENO
指向一个设备文件
默认打开状态 都是和当前终端绑定 输出到终端
不同的文件描述符可以对应同一个文件，多次调用fopen('a.txt'),对应的文件描述符不同，
何时释放：使用fclose 或linux的closeAPI时
找最小的没有被占用的文件描述符使用

使用Linux系统API open()获取文件描述符
后面使用read() write()传递的参数为文件描述符

### open打开文件
fopen函数底层调用open函数
man 2 系统API man 3 标准C库 
man 2 open

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

打开一个已经存在的文件
int open(const char *pathname, int flags);
    pathname —— 要打开的文件路径
    flags —— 对文件的操作权限设置还有其他的设置
    O_RDONLY, O_WRONLY, O_RDWR
    返回一个新的文件描述符，调用失败则返回-1
errno：属于Linux系统函数库，库里面的一个全局变量，记录的是最近的错误号
#include <stdio.h>
void perror(const char *s);
    s：用户描述，比如hello 最终输出： hello：XXX（实际错误描述）
作用：打印errorno对应的错误描述
创建一个新的文件
int open(const char *pathname, int flags, mode_t mode);
非函数重载 而是采用了可变参数

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main(){
    int fd = open("a.txt",O_RDONLY);
    if(fd == -1){
        perror("open";)
    }

    close(fd);
    return 0;
}

### open创建新文件
创建一个新的文件
int open(const char *pathname, int flags, mode_t mode);
    参数：
       - pathname:要创建的文件路径
       - flags：对文件的操作权限和其他设置
           - 必选项：O_RDONLY, O_WRONLY, O_RDWR 互斥
           - 可选项：O_CREAT 文件不存在，创建
       - mode：八进制数，表示创建出的新的文件的操作权限 rwx rwx r-x 0775 (最终权限mode & ~umask)  umask:0002 ~umask:0775 
        0777 -> 111 111 111
    &   0775 -> 111 111 101
    ------------------------
                111 111 101
        按位与：0和任何数都为0
        umask的作用就是抹去某些权限
        可以自己设置 umask 0022
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(){
    //创建一个新的文件
    int fd = open("create.txt", O_RDWR | O_CREAT, 0777);

    if(fd == -1){
        perror("open");
    }
    close(fd);
    return 0;
}
**O_RDWR | O_CREAT** 
flags参数是一个int类型的数据，占4个字节，32位。
flags 32位， 每一个就是一个标志位
1 - R 2 - W 3 - RW 4 -  CR 


### read write
#include <unistd.h>

ssize_t read(int fd, void *buf, size_t count);
    参数：
        - fd :文件描述符，open得到，通过fd操作文件
        - buf：需要读取数据存放的地方，数组的地址（传出参数）
        - count: 指定的数组的大小
    返回值：
        - 成功：
            - >0:返回实际读取到的字节数
            -  =0：文件已经读完了
        - 失败： -1 ，并设置errno

ssize_t write(int fd, const void *buf, size_t count);
    参数：
        - fd:文件描述符，open得到通过fd操作文件
        - buf:要网磁盘写入的数据
        - count：要写的数据实际的大小
    返回值：
        成功：实际写入的字节数
        失败：返回-1，并设置errno

文件拷贝代码
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    //通过open打开文件
    int srcfd = open("english.txt", O_RDONLY);
    if(srcfd == -1){
        perror("open");
        return -1;
    }
    //创建一个新文件
    int destfd = open("cpy.txt", O_RDWR | O_CREATE);
    if(destfd == -1){
        perror("open");
        return -1;
    }
    //频繁的读写操作
    char buf[1024] = {0};
    int len= 0;
    while((len = read(srcfd, buf, sizeof(buf))) > 0){
        write(destfd, buf, len);
    }

    //关闭文件
    close(srcfd);
    close(destfd);
}


### lseek

标准C库
#include <stdio.h>
int fseek(FILE *stream, long offset, int whence);
Linux系统函数
#include <sys/types.h>
#include <unistd.h>
off_t lseek(int fd, off_t offset, int whence);
    参数
        - fd:文件描述符,open得到的，通过fd来操作某个文件
        - offset：偏移量
        - whence：
            SEEK_SET 设置文件指针的偏移量
            SEEK_CUR 设置偏移量：当前位置 + 第二个参数offset大小
            SEEK_END 设置偏移量：文件大小 + 第二个参数offset值
    作用：
        1.移动文件指针到头文件
        lseek(fd,0,SEEK_SET);
        2.获取当前文件指针的位置
        lseek(fd, 0 ,SEEK_CUR);
        3.获取当前文件的长度
        lseek(fd, 0, SEEK_END);
        4.拓展文件的长度，当前文件10b, 110b, 增加了100个字节
        lseek(fd, 100, SEEK_END);
        需写一次数据
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(){
    //读取原文件
    int fd = open("hello.txt", O_RDWR);
    if(fd == -1){
        perror("open");
        return -1;
    }
    //扩展文件的长度
    int ret = lseek(fd, 100, SEEK_END);
    if(ret == -1){
        perror("lseek");
        return -1;
    }
    //写入空数据
    write(ret, " ", 1);

    //关闭文件
    close(fd);
    return 0;
}

### stat lstat函数
DESCRIPTION：返回一个文件的信息，放入statbuf中
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int stat(const char *pathname, struct stat *buf);
    作用：获取一个文件相关的信息
    参数：
        - pathname:操作文件的路径
        - statbuf：结构体变量，传出参数，用于保存获取到的文件信息
    返回值：
        成功：返回0
        失败：返回-1 设置errno



stat a.txt
    文件:文件名
    大小： 多少字节
    块：总共多少块
    IO块：一个块占用多少字节
    普通文件
    设备：文件所在设备的标识
    Inode：Linux中标识文件的值
    硬链接：多少链接
    权限：(0664/-rw-rw-r--)
    Uid:用户Id
    Gid：组Id
    最近访问：
    最近更改：


int lstat(const char *pathname, struct stat *buf);
    参数同stat


### 模拟实现ls -l
见ls-l.c

### 文件属性操作函数

//判断文件权限，判断文件是否存在
#include <unistd.h>
int access(const char *pathname, int mode);
    参数：
        - pathname:判断文件的路径
        - mode：
           - R_OK:是否有读权限
           - W_OK:判断是否有写权限
           - X_OK:判断是否有执行权限
           - F_OK:判断文件是否存在
    返回值：成功0 失败 - 1
//修改文件权限
int chmod(const char *pathname, mode_t mode);
//修改文件所有者
#include <unistd.h>
int chown(const char *pathname, uid_t owner, gid_t group);
//缩减或扩展某个文件到指定大小
int truncate(const char *path, off_t length);

### 目录操作
int chdir(const char *path);
作用：修改进程的工作目录
char *getcwd(char *buf, size_t size);
作用：获取当前工作目录
int mkdir(const char *pathname, mode_t mode);
作用：创建一个目录
int rename(const char *oldpath, const char *newpath);
重命名目录
## 递归实现目录遍历
opendir readdir closedir
### dup dup2
int dup(int oldfd);
作用：复制一个新的文件描述符
int dup2(int oldfd, int newfd);
作用：重定向文件描述符
### fcntl
int fcntl(int fd, int cmd, ... );
可以复制文件描述符，可以对文件描述符的状态进行设置或者获取



# Linux多线程开发

# Linux网络编程

# 项目实战