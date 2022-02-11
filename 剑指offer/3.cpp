#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int sizeOfNums = nums.size();
        // 先考虑特殊情况， 当数组为空返回-1
        if(sizeOfNums == 0){
            return -1;
        }
        // 当有数值不在0～n-1范围之内，返回-1
        for(int i = 0; i < sizeOfNums; i++){
            if(nums[i] < 0 || nums[i] >= sizeOfNums){
                return -1;
            }
        }
        int i = 0;
        while(i < sizeOfNums){
            // 遍历数组，正常递增数组应该满足nums[i] = i
            // i递增，进入下一个循环
            if(nums[i] != i){
                i++;
                continue;
            }
            // 当第i个位置的值m不等于i时，找第m个位置的值nums[nums[i]]
            // 若相等则返回m
            if(nums[i] == nums[nums[i]]){
                return nums[i];
            }
            swap(nums[nums[i]], nums[i]);

            
        }
        return -1;
    }
};



int main(){
    Solution * solu = new Solution();
    vector<int> nums{3, 4, 2, 0, 0, 1};
    int res = solu->findRepeatNumber(nums);
    cout << res << endl;
}