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

### 通信中如何确保发送的字节流是完整的？
序号为每个字节分配一个唯一的序号
seq = 110(3) 发送110 111 112
ack = 113 服务端期望下次接受序号为113的字节

### 如何确保多个报文的顺序一致
排列序号队列

只有当收到SYN和FIN时才会回复ack = seq + 1
ack :期望获取的对方发送的下一个序列号

-> SYN=1 cseq=1000
<- ACK=1 sack=1001
   SYN=1 sseq=2000
-> ACK=1 cack=2001

-> 1001(100) cack=2001 (希望下一次收到的服务器的发送字节号)
<- sack=1101 (希望下一次收到的客户端的发送字节号)
-> 1101(200) cack=2001
<- sack=1301
   
## 滑动窗口


## 四次挥手
调用了close
都可以主动发起断开连接，谁先调用close就是谁发起
断开时需要双向断开
-> FIN=1 
<- ACK=1
<- FIN=1
-> ACK=1

## TCP状态转换

### 三次握手
                     LISTEN
SYN_SENT(connect)
                     SYN_RCVD
ESTABLISHED
                     ESTABLISHED

### 四次挥手
FIN_WAIT_1(close)
                    CLOSE_WAIT
FIN_WAIT_2      
                    LAST_ACK
TIME_WAIT

2MSL 最大报文生存时间
主动断开连接的一方，最后进入一个TIME_WAIT状态，这个状态会持续2msl

## 半关闭、端口复用
主动关闭放进入FIN_WAIT_2状态 


#include <sys/types.h>
#include <sys/socket.h>
ssize_t recv(int sockfd, void *buf, size_t len, int flags);

查看网络相关信息的命令
netstat
    参数：
    -a 所有的socket
    -p 显示正在使用socket的程序的名称
    -n 直接使用IP地址，不通过域名服务器
    -l 正在监听的socket
    -t 使用tcp的socket
    -u udp

## 端口复用
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
int setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen);
    参数：
        - sockfd:要操作的文件描述符
        - level: 级别 - SOL_SOCKET(端口复用的级别)
        - optname: 选项的名称
          - SO_REUSEADDR
          - SO_REUSEPORT
        - optval: 端口复用的值（整形）
          - 1: 可以复用
          - 0：不可以复用
        - optlen: optval参数的大小
端口复用，设置时机是在服务器绑定端口之前
setsockport()
bind()

## ARP
根据 ip获取MAC
与IP协议不同

以太网帧 + ARP请求
以太网帧 + IP报文

arp -a
ip  mac对应缓存

### socket
socket是由IP地址和端口结合的，提供向应用层进程传送数据包的机制


## I/O多路复用（I/O多路转接）
输入：从文件到内存
输出：从内存到文件
socket：对内存中的fd(缓冲区读写数据)

I/O多路复用使得程序能同时监听多个文件描述符，能够提高程序的性能，Linux下实现I/O多路复用的系统调用主要有select、poll和epoll。

### 常见的I/O模型
### 阻塞等待(BIO Blocking IO)：
好处：不占用CPU宝贵的时间片
缺点：同一时刻只能处理一个操作，效率低

使用多线程(pthread_create)或多进程fork()解决
优点：能解决并发情况
缺点：
1.线程或者进程会消耗资源
2.线程或者进程调度会消耗CPU资源
根本问题：blocking

### 非阻塞， 忙轮询（NIO）
优点:提高了程序执行效率
缺点：需要占用更多的CPU和系统资源
使用IO多路转接技术select poll epoll
每循环内O(n)系统调用


### select/poll
通过遍历位来解决是否有消息到达，与NIO是有区别的

epoll不仅会告诉有几个客户端的数据到了，还会告诉是哪些客户端到了


首先构造一个关于文件描述符的列表，将要监听的文件描述符添加到列表中
调用一个系统函数，监听该列表中的文件描述符表，知道这些文件描述符表中的一个或者多个进行了I/O操作时，该函数才返回。
    函数是阻塞的
    函数对文件描述符的检测是由内核完成的
返回时，会告诉进程有多少（哪些）描述符要进程I/O操作。
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int select(int nfds, fd_set *readfds, fd_set *writefds,
            fd_set *exceptfds, struct timeval *timeout);
    - 参数：
        - nfds：委托内核检测的最大文件描述符 + 1
        - readfds：要检测的文件描述符的读的集合，委托内核检测哪些文件描述符的读的属性。一般只检测读操作，对应的是对方发送过来 的数据，因为读是被动的接受数据，检测的就是读缓冲区
            - 传入传出参数
        - writefds：要检测的文件描述符的写的集合，委托内核检测哪些文件描述符的写的属性
            - 委托内核检测写缓冲区是不是还可以写数据
        - exceptfds:检测发生异常的文件描述符的集合
        - timeout：设置的超时时间 struct timeval
            - NULL:永久阻塞，直到检测到了文件描述符有变化
            - =0 =0 不阻塞
            - >0 >0 阻塞对应的时间  
    - 返回值：
        - -1：失败 >n:检测的集合中有n各文件描述符发生了变化

传进第一位为1 有数据置为1 没有发生变化 返回1？？？

//将参数文件描述符fd对应的标志位设置为0
void FD_CLR(int fd, fd_set *set);
//判断fd对应的标志位是0还是1，返回值：fd对应的标志位的值0还是1
int  FD_ISSET(int fd, fd_set *set);
// 设置fd为1
void FD_SET(int fd, fd_set *set);
全设置为 0 1024个bit位
void FD_ZERO(fd_set *set);

select缺点:
1.每次调用select,需要把fd集合从用户态拷贝到内核态,这个开销在fd很多时会很大
2.同时每次调用select都需要在内核遍历传递进来的所有fd,这个开销在fd很多时也很大 for(int i= lfd +1;...)
3.select支持的文件描述符1024 ,小
4.fds不能重用每次需要重置 tmp = rdset   

## POLL
#include <poll.h>
int poll(struct pollfd *fds, nfds_t nfds, int timeout);
    参数:
        - fds: 是一个stuct pollfd 结构体数组,这是一个需要检测的文件描述符的集合
        - nfds:第一个参数数组最后一个有效元素下标 + 1
        - timout: 阻塞时长
            - 0:不阻塞
            - -1:阻塞,当检测到需要检测的文件描述符有变化,解除阻塞
            - >0:阻塞的时长
    - 返回值: -1 失败 >0 成功 n表示检测到集合中有n个文件描述符发生变化

#include <sys/epoll.h>
int epoll_create(int size);
    参数size:没有意义,随便写一个数,必须大于0
    返回值:-1 :失败 >0 文件描述符,操作epoll实例的

对epoll实例进行管理:添加文件描述符信息,删除信息,修改信息
int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);
    参数:
        - epfd:epoll实例对应的文件描述符
        - op: 要进行什么操作
            - EPOLL_CTL_ADD 增
            - EPOLL_CTL_MOD 改
            - EPOLL_CTL_DEL 删
        - event:检测文件描述符什么事情

typedef union epoll_data {
    void        *ptr;
    int          fd;
    uint32_t     u32;
    uint64_t     u64;
} epoll_data_t;

struct epoll_event {
    uint32_t     events;      /* Epoll events */
    epoll_data_t data;        /* User data variable */
};
常见的epoll检测事件:
    - EPOLLIN
    - EPOLLOUT
    - EPOLLERR

检测函数
int epoll_wait(int epfd, struct epoll_event *events,int maxevents, int timeout);
    - 参数:
        - epfd: epoll实例对应的文件描述符
        - events: 传出参数, 保存了发生了变化的文件描述符信息
        - maxevents:第二个结构体数组的大小
        - timeout
            - 0 不阻塞
            - -1 阻塞,直到检测到fd数据发生变化,解除阻塞
            - >0:阻塞的时长(毫秒)
    - 返回值 成功,返回发送变化的文件描述符的个数 >0
            - 失败 -1


## epoll的两种工作模式
在上述程序的哪里体现 wait？ read？
LT（水平触发）：
默认触发方式，同时支持block和non-block
内核告诉用户文件描述符是否就绪，然后可以对这个就绪的fd进行IO操作，。如果不做任何操作，内核还是会继续通知。

ET模式（边沿触发）
高速，只支持non-block，当文件描述符从未就绪到就绪，内核通过epoll告诉用户文件描述符已经就绪，并且不会再发送更多的通知。
epoll_event中设置 EPOLLET


## UDP
#include <sys/types.h>
#include <sys/socket.h>
ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,
                const struct sockaddr *dest_addr, socklen_t addrlen);
    - 参数：
        - sockfd： 通信的fd
        - buf: 要发送的数据
        - len: 要发送的数据长度
        - flags:0
        - dest_addr:通信的另外一端的地址信息
        - add_len:地址的内存大小
    - 返回值：成功，发送的字节数 失败：-1

ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,
                        struct sockaddr *src_addr, socklen_t *addrlen);
    - 参数：
        - sockfd:通信的fd
        - buf:接收数据的数组
        - flags：0
        - src_addr:用来保存另外一端的地址信息，不需要可以指定为NULL
        - add_len:地址的内存大小

## UDP中的广播
只能再局域网中用
客户端需要绑定服务器广播使用的端口，才可以接受到广播消息
与UDP差不多，但是服务器方需要设置属性， 客户端需要绑定广播端口


int setsockopt(int sockfd, int level, int optname,
                      const void *optval, socklen_t optlen);
    - sockfd:文件描述符
    - level: SO_SOCKET
    - optname: SO_BROADCAST
    - optval: int类型的值， 为1 ，表示允许广播
    - optlen: optval的大小

## 组播(多播)
一组IP接口
既可以用于局域网，也可以用于广域网
客户端需要加入多播组，才能接受到多播的数据
int setsockopt(int sockfd, int level, int optname,
                      const void *optval, socklen_t optlen);
    服务器设置多播信息
    - level: IPPROTO_IP
    - optname:IP_MULTICAST_IP
    - optval:struct in_addr
    - 

    //客户端加入到多播组
    - level：IPPROTO_IP
    - optname:IP_ADD_MEMBERSHIP
    - optval: sturct ip_mreq

## 本地套接字
本地的进程间通信
    有关系的进程间通信
    没有关系的进程间通信

流程：
服务器端：
1.创建监听的套接字 int lfd =socket(AF_UNIX/AF_LOCAL, SOCK_STREAM, 0);
2.监听的套接字绑定本地的套接字文件-》server
    struct sockaddr_un addr;
    //绑定成功，指定的sun_path中的套接字文件会自动生成
    bind(lfd, addr, len);
3.监听listen
4.等待连接请求
    struct sockaddr_un chliaddr;
    int cfd = accept(lfd, &chliaddr, len)
5.通信
    接收数据：read/recv
    发送：send/write
6.close

客户端
1.创建soket  int fd = socket(AF_UNIX/AF_LOCAL, SOCK_STEAM, 0);
2.监听的套接字绑定本
    struct sockaddr_un addr;
    //绑定成功，指定的sun_path中的套接字文件会自动生成
    bind(lfd, addr, len);地的IP端口
3.连接
    struct sockaddr_un serveraddr;
    connetc(fd, &serveraddr, sizeof(serveraddr));
4.通信
    接受数据
    发送
5.关闭连接


## 问题
服务和进程的区别

应用 进程 端口

发送端如何知道要发送的port ip (仅从应用程序能获取到吗)
mac(ARP 根据ip查找mac地址)


每一次握手都要经过一遍协议栈？根据缓存中的ip mac对应？

通道中无读端 报 SIGPIPE信号
无写端 ？

C中的void *

端口复用之后不会冲突吗

分页

vscode自动补全 apra/inet.h 的结构体

端口复用 和 I/O多路

拥塞控制和流量控制

EINTR