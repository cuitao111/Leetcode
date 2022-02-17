#include <iostream>
#include <vector>
#include <unordered_map>
#include<algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int sizeOfNums = nums.size();
        if(sizeOfNums < 3){
            return ans;
        }
        // 排序
        sort(nums.begin(),nums.end());
        // 枚举a
        for(int i = 0; i < sizeOfNums - 2; i++){
            // 需要和上一次的枚举不通
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            // 第三个指针
            int c = sizeOfNums - 1;
            // 枚举b
            for(int j = i + 1; j < sizeOfNums - 1; j++){
                // 不能枚举与上一个相同的
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue;
                }
                //如果c的值偏大， a+b+c > 0
                while(j < c && nums[i] + nums[j] + nums[c] > 0){
                    c--;
                } 
                // 不能枚举相同的c
                if(c == j){
                    break;
                }
                // 如果达到条件
                if(nums[i] + nums[j] + nums[c] == 0){
                    ans.push_back(vector<int>{nums[i],nums[j], nums[c]});
                }

            }
                
        }
        return ans;

    }
};

int main(){

}