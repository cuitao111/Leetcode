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
边界条件判断

由于数组不包含重复元素，并且只要当前的区间长度不为 11，
pivot 就不会与 high 重合；而如果当前的区间长度为 11，这说明我们已经可以结束二分查找了。因此不会存在 \textit{nums}[\textit{pivot}] = \textit{nums}[\textit{high}]nums[pivot]=nums[high] 的情况。
当只有两个元素时，如何选择左侧还是右侧

mid 刚刚好是最小值 只有两个值
递增 应该被包含在左侧 r = mid
递减 右侧 l = mid+1

*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(nums[r] > nums[mid]){
                // 最小值在左侧
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return nums[l];
    }
};

int main(){
    Solution * solu = new Solution();
    vector<int> nums{3,4,5,1,2};
    int res = solu->findMin(nums);
    cout << res << endl;

}