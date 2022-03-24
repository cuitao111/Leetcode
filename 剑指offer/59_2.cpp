#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <memory>
#include <queue>

using namespace std;

/*
最小栈时，使用额外的栈计算最小值
队列不能使用 当弹出时，入队与出队时的最小值不对应
用一个值来存储，出队之后的最大值

优先队列？
如何匹配 p_q 和 q
调用max_value时从堆中找，若top不在q中，不断弹出

如果我们向队列中插入数字序列 1 1 1 1 2，那么在第一个数字 2 被插入后，数字 2 前面的所有数字 1 将不会对结果产生影响。

q :    7   5 3 1
p :6 5 7 3 5 3 1
pop到7之前都不会影响 maxvalue的值
当 p要排除的值为7时 q也排除一个值
重点在于q的构造 push的过程
*/

class MaxQueue {
private:
    priority_queue<pair<int, int>> p_q;
    queue<int> q;
    int head, tail;
public:
    MaxQueue() {
        head = 0;
        tail = 0;

    }
    
    int max_value() {
        if(q.empty()){
            return -1;
        }
        while (p_q.top().second < head)
        {
            p_q.pop();
        }
        return p_q.top().first;
        
    }
    
    void push_back(int value) {
        // 存（value, 0）
        p_q.emplace(value, tail);
        q.emplace(value);
        tail++;
    }
    
    int pop_front() {
        if(q.empty()){
            return -1;
        }
        int res = q.front();
        q.pop();
        // 调用maxalue时若second < head时需要弹出
        // head = 1, (value,0).second < 1
        head++;
        return res;
    }
};