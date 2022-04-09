# Linux网络编程

sudo netstat -anp | grep sshd

ps aux | grep sshd 

## 网络模型
应用层：为应用程序提供服务
表示层：数据格式转化、数据加密
会话层：建立、管理和维护会话
传输层：建立、管理和维护端到端的连接
网络层：IP选址及路由选择
数据链路层：提供介质访问和链路管理
物理层：物理层

## 协议
最终体现出来都是发送数据的格式

### 封装和分用

## IP地址转换（字符串ip-整数）
int inet_pton(int af, const char *src, void *dst);
    af:地址族 AF_INET AF_INET6
    src:需要转换的点分十进制的IP字符串
    dst：转换后的结果

const char * inet_ntop(int at ,const void *src, char *dst, socklen_t size);
    af:地址族 AF_INET AF_INET6
    src:需要转换的ip整数地址
    dst:转换成IP地址字符串保存的地方
    size：第三个参数的大小（数组的大小）
    返回值：返回转换后的数据的地址（字符串），和dst是一样的

## TCP通信流程
// UDP 和 TCP --》传输层协议
UDP:用户数据报协议，面向无连接，可以单播，多播，广播，面向数据报，不可靠
TCP:传输控制协议，面向连接的协议，可靠的、基于字节流、仅支持单播传输

//服务器端（被动接受连接的角色）
1.**创建**一个用于监听的套接字
    - 监听：监听所有客户端的连接
    - 套接字：这个套接字就是一个文件描述符
2.将监听文件描述符与本地IP端口**绑定**（服务器地址信息）
    - 客户端连接服务器时就是使用的这个IP和端口
3.设置**监听**，监听fd 开始工作
4.阻塞等待，当有客户端发起连接，解除阻塞，接受客户端连接，会得到一个和客户端通信的套接字（不同于用于监听的套接字）
5.通信
    - 接受数据
    - 发送数据
6.通信结束，断开连接


// 客户端
1.创建一个用于通信的套接字(fd)
2.连接服务器，需要指定连接的服务器的IP和端口
3.连接成功了，客户端可以直接和服务器进行通信
    - 接受数据
    - 发送数据
4.通信结束，断开连接

### TCP UDP
是否创建连接
是否可靠
连接对象个数
传输方式
首部开销
控制
适用场景 实时应用 可靠性高的应用


## socket函数

#include <sys.types.h>
#include <sys/socket.h>
#include <arpa.inet.h> //包含这个头文件，上面两个可以省略


int socket(int domain, int type, int protocol);
    - 功能：创建一个套接字
    - 参数：
      - domain：协议族
          - AF_INET:ipv4
          - AF_INET6:ipv6
          - AF_UNIX, AF_LOCAL:本地套接字通信（进程间通信）
      - type：通信过程中使用的协议类型
        - SOCK_STREAM:流式协议
        - SOCK_DGRAM:报式协议
      - protocol:具体的协议。一般写0
        -  SOCK_STREAM：默认TCP
        -  SOCK_DGRAM：默认UDP
     - 返回值
       - 成功 文件描述符，操作的是内核缓冲区
       - 失败：-1 错误号

int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
    - 功能：绑定，将fd和本地IP + 端口进行绑定
    - 参数：
        - sockfd:通过sock函数得到的文件描述符
        - addr:需要绑定的socket地址，这个地址封装了ip的端口号信息
        - addr_len:addr占的内存大小
    - 返回值： 成功0 失败-1+错误号

int listen(int sockfd, int backlog);
    - 功能：监听这个socket上的连接
    - 参数：
        - sockfd：通过socket()得到的文件描述符
        - backlog:未连接的和已经连接的最大值,设置5就ok
    - 返回值： 成功0 失败-1+错误号
/proc/sys/net/core/somaxconn

int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
    - 功能：接受客户端连接，默认是一个阻塞的函数，等待客户端连接
    - 参数：
        - sockfd:用于监听文件描述符
        - addr：传出参数，记录了连接成功后客户端的地址信息（ip port）
        - addrlen:指定第二个参数对应的内存大小
    - 返回值：
      - 成功：返回用于通信的文件描述符
      - 失败：-1

int connect(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
    - 功能：用于通信的文件描述符
    - 参数：
        - sockfd:用于通信的文件描述符
        - addr:客户端要连接的服务器地址信息（通过协议栈获取）
        - addlen：第二个参数的内存大小

## TCP实现
作业：回射 将信息反传
客户端接受键盘录入 返回

## 三次握手
发送数据前，双方必须在彼此建立一条连接。所谓连接，其实是客户端和服务器内存里保存一份关于对方的信息，如IP 端口
TCP可以看成一种字节流，它会处理IP层或以下层的丢包、重复等错误问题。在建立连接过程中，双方需要交换一些连接参数。这些参数放在TCP头部。
TCP提供了一种可靠的、面向连接、字节流、传输层的服务，采用三次握手建立一个联机。采用四次挥手来关闭一个连接。

三次握手发生在客户端连接的时候，当调用connect()，底层会通过TCP协议进行三次握手。

ACK：确认
SYN：做连接
FIN：四次挥手

### 为什么不能两次
两端都要确认自己和对方都能接能收发数据， 两次服务端不能确定客户端的收数据能力。

### 为什么不能四次握手
四次握手也是可以的，但是为了方便将中间两步服务器的ACK与SYN一起

只有当ACK为1时，ack序号才有用




## ARP
根据 ip获取MAC
与IP协议不同

以太网帧 + ARP请求
以太网帧 + IP报文

arp -a
ip  mac对应缓存

### socket
socket是由IP地址和端口结合的，提供向应用层进程传送数据包的机制



## 问题
服务和进程的区别

应用 进程 端口

发送端如何知道要发送的port ip (仅从应用程序能获取到吗)
mac(ARP 根据ip查找mac地址)


每一次握手都要经过一遍协议栈？根据缓存中的ip mac对应？

通道中无读端 报 SIGPIPE信号
无写端 ？