#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>


using namespace std;

/*
首先要找出n维数组的所有三元组
如果限制 pos1x < pos1y < pos1z
i:0 ~ n - 3
j:i + 1 ~ n - 2
k:j + 1 ~ n - 1
只需判断pos2x < pos2y < pos2z

树状数组
左边的 1 的个数和右边的 0 的个数

找三元对 (x,y,z)一般先固定y 找左右两侧有无高效查找方法

两者都是 [0, 1, ..., n - 1] 的 排列
直接把nums[0]看作0
*/

class Solution {
public:

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[nums2[i]] = i;
        }
        long long res = 0;
        for(int i = 1; i < n-1; i++){
            // 找到nums2中nums[i]的位置
            int idx = mp[nums1[i]];
            // 左侧为1的个数
            int left = 0;
            for(int j = 0; j < i;j++){
                if(mp[nums1[j]] < idx){
                    left++;
                }
            }
            // 更新状态，表示在nums1中靠左侧
            res += (long)left * (n - 1 -idx -(i - left));
        }
        return res;

    }
};

int main(){
    Solution * solu = new Solution();
    vector<int> nums1{4,0,1,3,2};
    vector<int> nums2{4,1,0,2,3};
    long long res = solu->goodTriplets(nums1, nums2);
    cout << res <<endl;
    cin.get();
}