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
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int pos = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                nums[pos++] = nums[i];
            }
        }
        for(int i = pos;i < n;i++){
            nums[i] = 0;
        }
    }
};