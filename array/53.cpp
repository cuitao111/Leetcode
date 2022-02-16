#include <iostream>
#include <vector>
#include <unordered_map>
#include<algorithm>

using namespace std;

/*
连续数组,可以从左右两侧缩减入手
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sizeOfNums = nums.size();
        // 用pre维护f(i -1)
        int pre = 0;
        // 
        int maxList = 0;
        for(int i = 0; i < sizeOfNums; i++){
            pre = max(pre + nums[i], nums[i]);
            maxList = max(pre, maxList);
        }
        return maxList;
    }
};


int main(){
    Solution * solu = new Solution();
    vector<int> nums{0,0,-3,1};
    int res = solu->maxSubArray(nums);
    cout << res << endl;

}