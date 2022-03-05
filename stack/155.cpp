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
面试的时候被问到不能用额外空间，就去网上搜了下不用额外空间的做法。思路是栈里保存差值。
弹出时可以还原min
*/
// 用一个值来存储最小值，当弹出最小值时重新检索
class MinStack {
    stack<int> stk1;
    stack<int> stk2;
public:
    MinStack() {

    }
    
    void push(int val) {
        int minvalue;
        if(stk1.empty()){
            minvalue = val;
        }else{
            minvalue = min(val, stk2.top());
        }
        stk1.push(val);
        stk2.push(minvalue);
    }
    
    void pop() {
        stk1.pop();
        stk2.pop();
        
    }
    
    int top() {
        return stk1.top();
    }
    
    int getMin() {
        return stk2.top();
    }
};