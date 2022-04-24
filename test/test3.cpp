#include <iostream>
#include <vector>

using namespace std;

int getmindis(vector<int>& nums){
    int n = nums.size();
    vector<int> dp(n);
    dp[0] = nums[n -1] - nums[0];
    dp[n - 1] = dp[0];
    int min = dp[0];
    for(int i = 1; i < n; i++){
        dp[i] = abs(nums[i] - nums[0] -(nums[n - 1] - nums[i]));
        if(dp[i] < min){
            min = dp[i];
        }else{
            break;
        }
    }
    return min;

}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int res = getmindis(nums);
    cout << res <<endl;
    cin.get();
}