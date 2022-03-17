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
    int removeElement(vector<int>& nums, int val) {
        int n =  nums.size();
        int pos = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] ==  val){
                // pos不变
                continue;
            }
            if(i ==  pos){
                pos++;
                continue;
            }
            nums[pos] = nums[i];
            pos++;
        }
        return pos;
    }
};