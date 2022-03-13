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
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i++){
            if(i != 0 && nums[i] == nums[i - 1]){
                continue;
            }
            // 第一个数numsi
            
            for(int j = i + 1; j < n - 1; j++){
                int k = n - 1;
                while (nums[i] + nums[j] + nums[k] > target && j + 1 < k)
                {
                    k--;
                }
                cout << i << j << k <<endl;
                int abssum = abs(sum - target);
                int absk = abs(nums[i] + nums[j] + nums[k] - target);
                
                if(abs(sum - target) > abs(nums[i] + nums[j] + nums[k] - target)){
                    sum = nums[i] + nums[j] + nums[k];
                }
                if(k < n -1 && abs(sum - target) > abs(nums[i] + nums[j] + nums[k + 1] - target)){
                    sum = nums[i] + nums[j] + nums[k + 1];
                }
                //cout << i << j << k << sum << endl;
                
            }
        }
        return sum;
    }
};

int main(){
    Solution * solu = new Solution();
    vector<int> nums{1,2,5,10,11};
    int res = solu->threeSumClosest(nums, 12);
}