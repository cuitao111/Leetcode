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

// int 越界

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        long long tar = target;
        vector<vector<int>> res;
        if(n <= 3){
            return res;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < n - 3; i++){
            if(i != 0 && nums[i] == nums[i - 1]){
                continue;
            }
            for(int j = i + 1; j < n - 2; j++){
                if(j != i + 1 && nums[j] == nums[j - 1]){
                    continue;
                }
                for(int k = j + 1; k < n - 1; k++){
                    if(k != j + 1 && nums[k] == nums[k - 1]){
                        continue;
                    }
                    int four = n - 1;
                    long long sum;
                    while (four > k)
                    {
                        sum = (long)nums[i] + nums[j]+ nums[k] + nums[four];
                        if(sum <= tar){
                            break;
                        }
                        four--;
                    }
                    if(four > k && sum == tar){
                        vector<int> sub{nums[i], nums[j], nums[k], nums[four]};
                        res.push_back(sub);
                    }
                }
            }
        }
        return res;
    }
};


int main(){
    Solution * solu = new Solution();
    vector<int> nums{1000000000,1000000000,1000000000,1000000000};
    vector<vector<int>> res = solu->fourSum(nums, 0);
}