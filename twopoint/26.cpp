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

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int pos = 0;
        int num = nums[0];
        for(int i = 0; i < n; i++){
            if(i == 0){
                pos++;
                continue;
            }
            if(nums[i] != num){
                // 出现重复元素
                nums[pos] = nums[i];
                pos++;
                num = nums[i];
            }
        }
        return pos ;
    }
};