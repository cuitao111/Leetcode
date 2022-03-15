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
不能达到末尾的情况是中间有0， 0前面最长的也只能到0
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return true;
        }
        // if(nums[0] == 0){
        //     return true;
        // }
        int pos = n - 2;
        while(pos >= 0){
            if(nums[pos] != 0){
                pos--;
                continue;
            }
            // pos位置为0，向前找是否有越过pos的位置
            int pos1 = pos - 1;
            while (pos1 >= 0)
            {
                // pos1最远能达到的距离越不过pos
                if(pos1 + nums[pos1] > pos){
                    break;
                }
                pos1--;
            }
            // 如果找到了列表头部还是没有能越过pos的位置，说明无法达到最后
            // 这种情况包含了nums[0] == 0
            if(pos1 < 0){
                return false;
            }
            // 排除上述情况pos1的位置能达到末尾，继续向前找0
            pos = pos1 - 1;
        }
        return true;
        
    }
};


int main(){
    Solution * solu = new Solution();
    vector<int> nums{0};
    bool res = solu->canJump(nums);

}