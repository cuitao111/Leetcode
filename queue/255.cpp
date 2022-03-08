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
将一个queue移动到另一个中

*/

class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {

    }
    
    void push(int x) {
        // 哪个不为空就加到哪一个后面
        if(q1.empty()){
            q2.emplace(x);
        }else{
            q1.emplace(x);
        }
    }
    
    int pop() {
        int top;
        if(q2.empty()){
            while (!q1.empty())
            {
                top = q1.front();
                q1.pop();
                if(!q1.empty()){
                    q2.emplace(top);
                }
            }
        }else{
            while (!q2.empty())
            {
                top = q2.front();
                q2.pop();
                if(!q2.empty()){
                    q1.emplace(top);
                }
            }
        }
        return top;
    }
    
    int top() {
        int top;
        if(q2.empty()){
            while (!q1.empty())
            {
                top = q1.front();
                q1.pop();
                q2.emplace(top); 
            }
        }else{
            while (!q2.empty())
            {
                top = q2.front();
                q2.pop();
                q1.emplace(top);
            }
        }
        return top;
    }
    
    bool empty() {
        return (q1.empty() && q2.empty());
    }
};