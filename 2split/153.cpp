#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int findMin(vector<int> & nums){
        int n = nums.size();
        if(n == 0){
            return -1;
        }
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if(nums[mid] > nums[r]){
                // 最小值在右侧
                l = mid + 1;
            }else if(nums[mid] < nums[r]){
                // 最小值在左侧, mid也可能是最小值
                r = mid;
            }else{
                r = r - 1;
            }
        }
        return nums[l];
    }
};