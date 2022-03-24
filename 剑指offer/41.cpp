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
使用sum计算滑动窗口的总值，
不足size个时保存当前滑动窗口中的个数
*/

class MovingAverage {
    int maxsize;
    int curSize;
    queue<int> q;
    int sum;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        maxsize = size;
        curSize = 0;
        sum = 0;
    }
    
    double next(int val) {
        // 将val加入队列
        q.emplace(val);
        sum += val;
        curSize++;
        if(curSize > maxsize){
            sum -= q.front();
            q.pop();
            curSize--;
        }
        return sum * 1.0 / curSize;
    }
};