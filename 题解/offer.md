https://www.bilibili.com/video/BV1zK4y1r7tn?p=2&vd_source=1f4a7a119cba75354caa87a52ab8737c

6 快排：43 归并 背包

1. 数组中重复的数字
hashmap
限定了范围，直接用下标
while(nums[i] != i){
    if(nums[i] == nums[nums[i]]){return} //结果
    else 交换
}
例子：
0 1 2 3 4 5 6 
2 3 1 0 2 5 3

2. 不修改数组找出重复数字
二分


3. 二维数组中的查找
从右上角 删除行或者列

4. 替换空格
先统计空格出现的次数
然后倒序替换，不会出现赋值覆盖的情况

5. 从尾到头打印链表
stack
存到vector result
return vector(res.rbegin(), rend())

6. 重建二叉树
dfs 给前序和中序
helper(root, preorder, inorder, inStart, preStart, preEnd)
用map记录中序的元素位置，就不需要查找，能直接获得子树的长度

7. 二叉树的下一个节点 中序的下一个节点
右子树存在，返回右子树最左侧的节点
右子树不存在 只有左子树（或者都没有） p是根节点（没父节点） return null
                                   p不是根节点 如果p是左孩子 if(p == p->next->left) 返回父节点
                                              p是右孩子 p=p->next;

8. 两个栈实现队列

push ：全push到stk1
pop: 1->2  2.top pop()
2-> 1

push：全push到stk1
如果stk2为空 把stk1倒入stk2
如果不为空直接返回stk2的top()

9. 求斐波那契数列的第n项
迭代 第n项 for(2~n) 第二项是1  res = a(0) +b(1) a = b b = res
                      

10. 旋转数组的最小数字
二分 hot17题 找到具体数字
二分 找mid 左右两部分一定有一部分有序
判断target是否在有序序列中来选择左右
先保证 后面始终小于前面 while（nums[n] == nums[n]) n--;
如果还是升序 递增数列

11. 矩阵中的路径
dfs hot34 单词搜索

12. 机器人的运动范围
bfs dfs
%10 /10

13. 剪绳子 剪成m段 求最大乘积
当长度为>=5 可以拆成 3* （ni - 3） > ni
4 拆成 2 2 / 1 3
3 > 1*2
2 > 1*1
res *= 4; n-=4;
最优： 33 。把绳子尽可能切为多个长度为 33 的片段，留下的最后一段绳子的长度可能为 0,1,20,1,2 三种情况。
次优： 22 。若最后一段绳子长度为 22 ；则保留，不再拆为 1+11+1 。
最差： 11 。若最后一段绳子长度为 11 ；则应把一份 3 + 13+1 替换为 2 + 22+2，因为 2 \times 2 > 3 \times 12×2>3×1。

dp 枚举所有切分情况

14. 二进制中1的个数
or (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                ret++;
            }
        }

15. 数值的整数次方
递归 +  n /2
直接算n次乘法也可，但是递归时间复杂度 logn

16. 打印1到最大的n位数
大数问题 需要用string

17. 删除链表中的重复节点 排序链表
1->2->3->3->4->4->5
1-> 2 -> 5

往后找到重复的节点

18. 正则表达式匹配
dp
s和p
根据p的下一位是否为*
不是* 判断一个字符
是* 

19. 判断表示数值的字符串
官方题解为有限状态机

20. 调整数组顺序使奇数位于前半部分
双指针
从左侧向右找偶数
不需要保存顺序
如有需要，使用queue

21. 倒数第k 个节点
两个指针

22. 翻转链表

23. 合并两个排序链表
while

24. 树的子结构 判断b是否是a的子结构
递归 递归判断a的节点
judge（a.left, b）
judge(a.r, b)
recur(a,b)
def recur(A, B):
            if not B: return True //b为空，判断完成，直接返回true
            if not A or A.val != B.val: return False
            return recur(A.left, B.left) and recur(A.right, B.right)

25. 二叉树的镜像
hot 65
dfs helper
l = invertTree(root.l)
r = invertTree(root.r)
赋值一下

26.  对称的二叉树 hot40
helper（root.left, root.right）
结束： p=q=null
p或者q有一个为null
pq值不等
return help（p.left,q.right） && help（q.left,p.right）

27. 顺时针打印矩阵
打印一圈的时候起始和终止条件是什么
top bottom left right 始终位于未打印的数上
column row
左->右：
l-》r 改变top ++
增大top 是否大于bottom
上-》下：
改变right --
判断right 是否 小于left
右-》左：
改变bottom --
判断bottom < top
下-》上：
改变left++
判断left是否》 right


28. 包含min函数的栈
用两个栈来实现
出栈判断是否大于小栈顶

29. 栈的压入弹出序列
判断弹出序列是否正确
用stack模拟
判断是否栈里为空 且 弹出序列到底

30. 从上到下打印二叉树
queue

31. 二叉搜索树的后序遍历序列
判断是否为后序遍历
分治
单调栈
划分左右子树 判断左小 右大
从左向右找第一个大于 i位置的数  看是否到右侧
def recur(i, j):
    if i >= j: return True
    p = i
    while postorder[p] < postorder[j]: p += 1
    m = p
    while postorder[p] > postorder[j]: p += 1
    return p == j and recur(i, m - 1) and recur(m, j - 1)

32. 和为某一值的路径
dfs
helper(Node, target)
前序

33. 复杂链表的复制
Random
回溯 + 哈希表 unordered_map<Node*, Node*> cachedNode;
迭代 + 节点拆分
把新节点插到后节点的位置

34. 二叉搜索树与双向链表 转换成排序的循环双向链表
dfs 中序遍历
Node *pre, *head;
void dfs(Node* cur) {
    if(cur == nullptr) return;
    dfs(cur->left);
    if(pre != nullptr) pre->right = cur;
    else head = cur;
    cur->left = pre;
    pre = cur;
    dfs(cur->right);
}
最后连一下头尾
每次要练一个节点前面已经是双向链表了

35. 序列化二叉树
hot 75 
空节点也需要被记录，这样可以保持反序列化时树的结构唯一
层次遍历
queue
string->list<string> 遇到，再push
list<string> dataArray;
string str;
for (auto& ch : data) {
    if (ch == ',') {
        dataArray.push_back(str);
        str.clear();
    } else {
        str.push_back(ch);
    }
}
if (!str.empty()) {
    dataArray.push_back(str);
    str.clear();
}
return rdeserialize(dataArray);

36. 字符串的排列
先按顺序排列一下， 再用递归
用set或者下main的if语句避免重复的排列
if (vis[j] || (j > 0 && !vis[j - 1] && s[j - 1] == s[j])) {
                continue;
            }

37. 数组中超过一般的数字
hot57
hash 
3.moore voting algorithm
每次找出一对不同元素，从数组中删除，直到只有一种
使用一个count和res就可以实现
for（num）
 if(count == 0)
  res = num; //将当前数字设为候选
 if num != res:
  count--;
 else
  count++;
return res;

38. 最小的k个数
最大堆


39. 数据流中的中位数

使用两个堆来实现
左半侧的比较小的数放入最大堆 ，大数放在最小堆
size相等， 放入minHeap++
否则放入maxheap
放入minHeap需要先过一遍maxHeap ，保证顺序
同理，放入大堆时也要过一遍minHeap


40. 连续子数组的最大和
dp 以某数字结尾的最大和 dp[i] = max(dp[i], dp[i-1] + nums[i])
不需要数组
hot100中搜索连续， 最大

41. 1~n中1出现的次数
1在各个计数位上出现的次数
例：1在百位上出现的次数  当前位cur = 5 > 1
    3101 5 92     a = n // base // 10
                  b = n % base
1.**（a+1）*base**   (3101+1) * 100   
   
    1在千位  cur = 1
310 1 592
a = 310 base = 1000
1.000-309 a*base  310 * 1000
2.310 1 * b+1   (1* 592 + 1)
**a*base+b+1**

    1在万位  cur = 0
31 0 1592
**a * base**  31 * 10000
遍历一遍，根据公式求和

42. 数字序列中某一位的数字 找规律
面试应该不会考

43. 把数组排成最小的数
自定义排序规则


44. 把数字翻译成字符串
dp[i] 从第i位数字开始不同的翻译数目
dp[i] = dp[i + 1] + g[i, i+1] * f[i + 2]
g():若s[i]s[i + 1] 在[10,25]之间则为1 否则为 0
空间复杂度优化 O（n） -> O(1)
a = b = 1
a,b = (a+b if 9 < x*10+y < 26 else a), a
每一位的数字也需要更新 x y

45. 礼物的最大价值
dp[i][j] 到格子i,j所拿到的礼物的最大值
dp[i][j] = max(dp[i][j - 1],dp[i-1][j])+ gift[i][j]

空间优化:O(n^2) -> O(n)
顺序 按行扫描

46. 丑数
最小堆
另外一种简单方法 dp
vector<int> dp(n + 1);
dp[1] = 1;
int p2 = 1, p3 = 1, p5 = 1;
for (int i = 2; i <= n; i++) {
    int num2 = dp[p2] * 2, num3 = dp[p3] * 3, num5 = dp[p5] * 5;
    dp[i] = min(min(num2, num3), num5);
    if (dp[i] == num2) p2++;
    if (dp[i] == num3) p3++;
    if (dp[i] == num5) p5++;
}
return dp[n];

47. 第一个只出现一次的字符
hashmap遍历两次 
空间优化 int -> bool
时间优化：主要是第二次遍历
遍历字符串-》遍历字典 

48. 数组中的逆序对
归并排序 
        i:9 9  j:0 5
tmp:0   i:9 9  j: 5   0来自j且 i剩余2 需要+2逆序对

        i:2 5  j:3 8
tmp:2   i:5    j:3 8    +0
tmp:23                  +1

49. 两个链表第一个公共节点

50. 排序数组中查找数字
二分 +0.5 hot 18

53. 0-1中缺失的数字
二分 下标
判断条件 l<=r
l<-m + 1   r<-m-1
hot 74 90 置为负数 都在0——1范围之内

54. 二叉搜索树第k大的节点
中序遍历逆序 右中左

55. 二叉树的深度
max(l, r)+ 1 dfs

56. 数组中数字出现的次数
找出只出现一次的两个数 位运算
??

57. 数组中数字出现的次数Ⅱ
其他数字只出现三次
每一位和一定是3的倍数

58. 和为s的两个数字
双指针


59. 和为s的连续正数序列
hot 95
暴力枚举

60. 翻转单词顺序
双指针 遇到空格 截取出i~j的单词 存入vector<string>
然后i一直往前直到遇到非空格
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。

61. 左旋转字符串
string内部翻转 string之间翻转

62. 滑动窗口的最大值
hot69

63. 队列的最大值
类似最小栈用一个deque和一个queue实现
类似62 滑动窗口的最大值

64. n个骰子的点数 
dp

65. 扑克牌中的顺子
有重复false 大小王 false
[1,2,5]也算顺子？

66. 圆圈中最后剩下的数字
迭代 %

67. 股票的最大利润
记录之前的最小值

68. 1+2+。。n
递归 
快速乘

69. 不用加减乘除做加法
位运算

70. 构建乘积数组
hot 68. 求除自身之外的乘积

71. 把字符串转换成整数
自动机

72. 二叉树的最近公共祖先
后序遍历
hot 67. 二叉树的公共祖先

73. 最近公共祖先Ⅱ


















