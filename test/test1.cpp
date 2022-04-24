#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:
    int get7nums(vector<int> & nums){
        // 从位置i到末尾的子集
        int sum = 0;
        int res = 0;
        return backstrack(nums, 0, sum);
    }

    int backstrack(vector<int> & nums, int begin, int pre_sum){
        // 当begin达到末尾，presum为和，判断是否整除7
        if(begin == nums.size()){
            if(pre_sum % 7 == 0){
                return pre_sum;
            }else{
                return 0;
            }
        }
        // begin位置的元素可以要也可以不要
        // 当nums[begin]为7的倍数时，可以作为一种结果
        int add = backstrack(nums, begin + 1, pre_sum + nums[begin]);
        int noadd = backstrack(nums,begin + 1, pre_sum);


        int res = max(add, noadd);
        if(pre_sum % 7 == 0){
            res = max(res, pre_sum);
        }
        return res;
        
    }
};

int main(){
    Solution * solu = new Solution();
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i]; 
    }
    int res = solu->get7nums(nums);
    cout << res <<endl;
}