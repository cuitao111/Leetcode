#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l < r){
            // 从左向右找第一个偶数
            while(nums[l] % 2 != 0){
                l++;
            }
            while(nums[r] % 2 == 0){
                r--;
            }
            if(l < r){
                int temp = nums[l];
                nums[l] = nums[r];
                nums[r ]= temp;
            }
        }
        return nums;
    }
};

int main(){
    vector<int> nums{1,3,5};
    Solution * solu = new Solution();
    vector<int> res =  solu->exchange(nums);
    for(int i = 0; i < res.size();i++){
        cout << nums[i];
    }
    cin.get();

}