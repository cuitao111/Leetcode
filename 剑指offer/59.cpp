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
当上一个位置的窗口的第一个位置为最大值
滑动时，最大值排出，需要重新计算最大值
每次保存后k-1个数中的最大值 不可行，同上

*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int sizeOfNums = nums.size();
        if(sizeOfNums == 0){
            return nums;
        }
        // 优先队列 堆 emplace入栈时 自动把最大值推导栈顶
        priority_queue<pair<int, int>> q;
        vector<int> res;
        for(int i = 0; i < k; i++){
            q.emplace(nums[i], i);
        }

        res.push_back(q.top().first);
        for(int i = k;i < sizeOfNums; i++){
            q.emplace(nums[i], i);
            // 如果不再滑动窗口内
            while(q.top().second < i - k + 1){
                q.pop();
            }
            res.push_back(q.top().first);
        }
        return res;
    }
};

int main(){
    Solution * solu = new Solution();
    vector<int> nums{9,10,9,-7,-4,-8,2,-6};
    int k = 5;
    vector<int> res = solu->maxSlidingWindow(nums, k);

}