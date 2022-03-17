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
需要遍历所有可能结果
[6,2,4]
6入栈之后， 处理2时 将6和2放在一起还是 2和4放在一起
知道了数组长度之后，能否计算出构成的二叉树种类
*/

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        stack<int> stk;
        int res = 0;
        stk.push(20);
        for(int i = 0; i < arr.size(); i++){
            while (arr[i] >= stk.top())
            {
                int minvalue = stk.top();
                stk.pop();
                int left= stk.top();
                res += minvalue * min(left, arr[i]);
            }
            stk.push(arr[i]);
            
        }
        while (stk.size() > 2){
            int value = stk.top();
            stk.pop();
            res += value * stk.top();
        }
        return res;
        
    }
};