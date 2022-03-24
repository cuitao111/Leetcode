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
参考函数调用，没有return的函数被压在栈底
[[],2,[]] 没有获取完毕的List也被压在栈底
递归的方式，输出顺序错误
*/

class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

/*
class NestedIterator {
    queue<int> q;
public:
    void pushList(const vector<NestedInteger> &nestedList){
        int sizeOfList = nestedList.size();
        for(int i = 0; i < sizeOfList; i++){
            if(nestedList[i].isInteger()){
                q.push(nestedList[i].getInteger());
            }else{
                pushList(nestedList[i].getList());
            }
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        pushList(nestedList);
    }
    
    int next() {
        return q.front();
        q.pop();
    }
    
    bool hasNext() {
        return !q.empty();
    }
};
*/

class NestedIterator {
private:
    stack<pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>> stk;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        stk.emplace(nestedList.begin(), nestedList.end());
    }
    
    int next() {
        return stk.top().first++->getInteger();
    }
    
    bool hasNext() {
        while (!stk.empty())
        {
            auto &p = stk.top();
            if(p.first == p.second){
                stk.pop();
                continue;
            }
            if(p.first->isInteger()){
                return true;
            }
            // 当前元素为列表，入栈
            // 迭代器指向下一个元素，这样处理完列表之后，处理外层的下一个元素
            auto &lst = p.first++->getList();
            stk.emplace(lst.begin(), lst.end());
        }
        return false;
        
        
    }
};
