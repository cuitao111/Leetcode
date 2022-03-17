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

class MyCircularQueue {
    int sizeOfQ;
    vector<int> q;
    int head, tail;
public:
    MyCircularQueue(int k) {
        // 空head = tail
        // 满tail = head + 1
        // 使用取余循环
        q.resize(k + 1);
        sizeOfQ = k + 1;
        head = 0; 
        tail = 0;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        // 从初始状态开始 tail=0处插入
        // ++在前用前加
        tail = (tail + 1) % sizeOfQ;

        q[tail] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        // head+1的位置出栈
        head = (head + 1) % sizeOfQ;
        return true;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return q[((head + 1) % sizeOfQ)];
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return q[tail];
    }
    
    bool isEmpty() {
        return (head % sizeOfQ) == (tail % sizeOfQ);
    }
    
    bool isFull() {
        return (head % sizeOfQ) == ((tail + 1) % sizeOfQ);
    }
};