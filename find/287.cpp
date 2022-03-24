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
要求不修改数组，不能排序，也不能额外建立一个排好序的数组
暴力法 O(n^2)

最终结果一定在[1,n]中间，因此可以不断缩减该区域
取中间index mid 如果cnd[mid] <= mid 说明结果在 [mid, n]之间
这样不需要计算所有1-n个cnt的值，只需要n*logn的时间复杂度
如果构建cnt，需要时间n*n 和空间n
题解中只在mid时调用了构建cnt的过程
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 1, r = n - 1, ans = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                cnt += nums[i] <= mid;
            }
            if (cnt <= mid) {
                l = mid + 1;
            } else {
                r = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
};


int main(){
    Solution * solu = new Solution();
    vector<int> nums{1,3,3,2,4,5,6};
    int res  = solu->findDuplicate(nums);
    cout << res << endl;
}