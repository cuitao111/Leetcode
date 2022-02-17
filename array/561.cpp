#include <iostream>
#include <vector>
#include <unordered_map>
#include<algorithm>

using namespace std;

/*
思路一：
直接从小到大排列，两个一组
经过复杂的数学推导，可行


思路二；
把所有可能的结果列出，取最大
可行，但时间空间复杂度高
*/

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int sizeOfNums = nums.size();
        // 非偶数返回-1；
        if(sizeOfNums % 2 != 0){
            return -1;
        }
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < sizeOfNums; i+=2){
            ans += min(nums[i], nums[i + 1]);
        }
        return ans;
    }
};


int main(){

}