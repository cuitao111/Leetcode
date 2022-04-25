#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution{
    
public:
    int max_cnt;
    int max_num;
    Solution(){
        max_cnt = 0;
        max_num = 0;
    }

    int getMaxnum(vector<int> &nums){
        int n = nums.size();
        if(n == 0){
            return  -1;
        }
        unordered_map<int, int> map;
        for(int i = 0; i < n; i++){
            map[nums[i]]++;
        }
        for(int i = 0; i < n; i++){
            if(max_cnt <  map[nums[i]]){
                max_num = nums[i];
                max_cnt = map[nums[i]];
            }
            // max_cnt = max(max_cnt, map[nums[i]]);
        }
        return max_cnt;
    }

};




int main(){
    vector<int> nums{2,3,1,5,5,5,5,7,8,1};
    Solution * solu = new Solution();
    solu->getMaxnum(nums);
    cout << solu->max_num << "  " << solu->max_cnt << endl;
    cin.get();
}