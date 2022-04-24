#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        int res;
        // 存下标
        stack<int> stk;
        for(int i = 0; i < n; i++){
            if(!stk.empty()){
                int top = stk.top();
                if(nums[i] != nums[top]){

                    stk.pop();
                    if(!stk.empty()){
                        int left = stk.top();
                        stk.pop();
                        // 判断left top 和 nums[i]是否构成结果
                         if(nums[left] > nums[top] && nums[top] < nums[i]){
                             res++;
                         }else if(nums[left] < nums[top] && nums[top] > nums[i]){
                             res++;
                         }
                    }
                    // 把top压回stk充当下一次left
                    stk.push(top);
                }
            }
            if(stk.empty()){
                stk.push(i);
            }else if(nums[i] != nums[stk.top()]){
                stk.push(i);
            }
        }
        return res;
    }
};

int main(){
    Solution * solu = new Solution();
    vector<int> nums{2,4,1,1,6,5};
    int res = solu->countHillValley(nums);
    cout << res << endl;
    cin.get();
}