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
从后往前，最后一位需要的步数位0
第i位需要的步数位min(后续位置+)


优化
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        vector<int> step(n);
        step[n - 1] = 0;
        int pos = n - 2;
        while(pos >= 0){
            if(nums[pos] == 0){
                step[pos] = n + 1;
                pos--;
                continue; 
            }
            step[pos] = 1 + step[pos + 1];
            // 此处pos+i可能越界
            // 当i = n -pos时刚好达到有边界
            int bound = min(nums[pos], n - 1 - pos);
            for(int i = 1; i <= bound; i++){
                step[pos] = min(step[pos], 1 + step[pos + i]);
            }
            pos--;
        }
        return step[0];
    }
};

int main(){
    Solution * solu = new Solution();
    vector<int> nums{2,1};
    int res = solu->jump(nums);
}