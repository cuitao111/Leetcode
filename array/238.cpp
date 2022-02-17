#include <iostream>
#include <vector>
#include <unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sizeOfNums = nums.size();
        // 定义返回数组，并初始化为全0；
        vector<int> ans(sizeOfNums, 0);
        // 初始化L R
        vector<int> lproduct(sizeOfNums);
        vector<int> rproduct(sizeOfNums);
        lproduct[0] = 1;
        rproduct[sizeOfNums - 1] = 1;
        for(int i = 1; i < sizeOfNums; i++){
            lproduct[i] = lproduct[i - 1] * nums[i - 1];
        } 
        for(int i = sizeOfNums - 2; i >= 0; i--){
            rproduct[i] = rproduct[i + 1] * nums[i + 1];
        }
        for(int i = 0; i < sizeOfNums; i++){
            ans[i] = lproduct[i] * rproduct[i];
        }
        return ans;
    }
};

int main(){
    Solution * solu = new Solution();
    vector<int> nums{1,2,3,4};
    vector<int> res = solu->productExceptSelf(nums);
}