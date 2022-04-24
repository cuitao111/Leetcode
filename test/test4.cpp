#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getmidnum(vector<int>& nums, int i, int j){
    int midi = i + (j - i) / 2;
    vector<int> newnum(j - i + 1);
    for(int k = i; k <= j; k++){
        newnum[k - i] = nums[k];
    }
    sort(newnum.begin(), newnum.end());
    return newnum[midi - i];
}

int getSum(vector<int> & nums){
    int n = nums.size();
    int res = 0;
    for(int i = 0; i < n; i++){
        res += nums[i];
        for(int j = i + 2; j < n; j += 2){
            // 从nums中获得第（i+j)/2小的数
            res += getmidnum(nums, i , j);
        }
    }
    return res;

}



int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int res = getSum(nums);
    cout << res << endl;
}