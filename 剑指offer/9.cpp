#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <memory>
#include <queue>
#include <list>

using namespace std;

/*
stk1倒入stk2后没必要倒回
可以将stk2倒接到stk1上形成一个队列
*/

class CQueue {
    stack<int> stk1, stk2;
    int curstk = 1;
public:
    CQueue() {
        while (!stk1.empty()) {
            stk1.pop();
        }
        while (!stk2.empty()) {
            stk2.pop();
        }

    }
    
    void appendTail(int value) {
        
        stk1.push(value);
        
    }
    
    int deleteHead() {
        if(stk1.empty()){
            return -1;
        }
        // 将stk1全部倒入stk2，再倒回
        while (!stk1.empty())
        {
            stk2.push(stk1.top());
            stk1.pop();
        }
        int res = stk2.top();
        stk2.pop();
        while (!stk2.empty())
        {
            stk1.push(stk2.top());
            stk2.pop();
        }
        return res;
        

    }
};