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
单调栈
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int sizeOfT = temperatures.size();
        if(sizeOfT == 0){
            return temperatures;
        }
        // 用来存储下标的栈
        // 最后留在栈里的一定是之后气温高的ans = 0
        // 所以栈里单调递减
        // 当i出栈时，说明遇到高于第i天的气温， ans[i]能够确定
        stack<int> stk;
        vector<int> ans(sizeOfT);
        for(int i = 0; i < sizeOfT; i++){
            while(!stk.empty() && temperatures[i] > temperatures[stk.top()]){
                ans[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        while (!stk.empty())
        {
            ans[stk.top()] = 0;
            stk.pop();
        }

        return ans;
        
    }
};