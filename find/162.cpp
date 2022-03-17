#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <memory>
#include <queue>
#include <list>
#include <numeric>

using namespace std;

/*
你可以假设 nums[-1] = nums[n] = -∞ 。指端点的元素可作为峰值
滑动窗口
结果肯定在1-n范围内，二分判断
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return -1;
        }
        if(n == 1){
            return 0;
        }
        if(nums[0] > nums[1]){
            return 0;
        }
        if(nums[n-1] > nums[n - 2]){
            return n - 1;
        }
        int l = 1, r = n - 2;
        while (l <= r)
        {
            int mid = l + (r -l) / 2;

            if(nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]){
                return mid;
            }

            if(nums[mid] < nums[mid + 1]){
                // 到右侧找
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return l;
        
    }
};