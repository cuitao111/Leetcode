#include <iostream>
#include <vector>
#include <stack>


using namespace std;



class Solution {
public:

    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        // 默认左侧最近最小的位置为0
        // 逐步
        vector<int> left(n), right(n, n-1);
        // 单调递增栈
        stack<int> stk;
        for(int i = 0; i < n; i++){
            // 保证单调递增，如果顶部元素要大，说明改元素找到了右侧最近最小值
            while(!stk.empty() && nums[stk.top()] > nums[i]){
                // 为什么是非严格定义的？
                // [3,4,5,3,7] 第一个三完全可以延申到n-1
                right[stk.top()] = i - 1;
                stk.pop();
            }

            if(!stk.empty()){
                // 单调递增，
                left[i] = stk.top() + 1;
            }
            stk.push(i);
        }

        vector<long long> pre(n+1);
        for(int i = 1; i <= n; i++){
            pre[i] = pre[i - 1] + nums[i - 1];
        }

        long long res = 0;
        for(int i = 0; i < n; i++){
            // 以i位置的值为最小
            // nums[i] * (right - left)
            res = max(res, nums[i] *(pre[right[i] + 1] - pre[left[i]]));
        }
        return res % 1000000007;
    }
};


int main(){

    Solution * solu = new Solution();
    vector<int> nums = {1,2,3,2};
    int res = solu->maxSumMinProduct(nums);

    cout << res << endl;
    cin.get();



    return 0;
}