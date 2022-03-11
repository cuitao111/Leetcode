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
数组越分割，数量越多，上界越小
极端的两种情况 
每个数组只有一个值，数组共n个， 上界为最大值
整个数组    共1个，上界为所有的和
我们需要找到最小上界
找出以mid为上界的需要分割的数组
当分割数组有富裕，可以继续分降低下届，到左侧找
当无富裕 ，需要扩张上界，减少分割成的数组量
*/

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int sizeOfNums = nums.size();
        if(sizeOfNums == 0){
            return 0;
        }
        // 下届
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            // 计算以mid为上界需要的分割的数组量cnt
            int cnt = calculateCnt(nums, mid);

            if(cnt <= m){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }

    int calculateCnt(vector<int>& nums, int mid){
        // 初始情况为整体一个数组
        int cnt = 1;
        // 贪心，从头到尾构建子数组
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(sum + nums[i] > mid){
                // 将i处的值作为新子数组的开头
                sum = nums[i];
                cnt++;
            }else{
                sum += nums[i];
            }
        }
        return cnt;
    }
};

int main(){
    Solution * solu = new Solution();
    vector<int>  nums{7,2,5,10,8};
    int res = solu->calculateCnt(nums, 2);
}