#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <memory>
#include <queue>
#include <list>

using namespace std;

/*
比较m1 * m2次
从前往后，双指针？
*/

class Solution{
public:
    int findn(vector<vector<int>> nums1, vector<vector<int>> nums2){
        int pos1 = 0, pos2 = 0;
        // nums1 和nums2是否排好序？
        int m1 = nums1.size(), m2 = nums2.size();
        int res = 0;
        while(pos1 < m1 && pos2 < m2){
            // 比较nums1[pos1] he nums2[pos2]是否有重合
            if(nums1[pos1][0] > nums2[pos2][1]){
                pos2++;
                continue;
            }
            if(nums1[pos1][1] < nums2[pos2][0]){
                pos1++;
                continue;
            }
            if(nums1[pos1][0] <= nums2[pos2][0] && nums1[pos1][1] >= nums2[pos2][1]){
                // 1包含2 2后退
                res += (nums2[pos2][1] - nums2[pos2][0] + 1);
                pos2++;
                continue;
            }
            if(nums1[pos1][0] <= nums2[pos2][0] && nums1[pos1][1] >= nums2[pos2][1]){
                // 2包含1
                res += (nums1[pos1][1] - nums1[pos1][0] + 1);
                pos1++;
                continue;
            }
            // 重叠但不包含
            if(nums1[pos1][0] <= nums2[pos2][0]){
                // 1在前
                res += (nums1[pos1][1] - nums2[pos2][0] + 1);
                pos1++;
            }else{
                // 2在前
                res += (nums2[pos2][1] - nums1[pos1][0] + 1);
                pos2++;
            }

        }
        return res;
    }
};


int main(){
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<vector<int>> nums1(m1, vector<int>(2)), nums2(m2, vector<int>(2));
    for(int i = 0; i < m1; i++){
        cin >> nums1[i][0];
    }
    for(int i = 0; i < m1; i++){
        cin >> nums1[i][1];
    }

    for(int i = 0; i < m2; i++){
        cin >> nums2[i][0];
    }
    for(int i = 0; i < m2; i++){
        cin >> nums2[i][1];
    }
    // int n = 10, m1 = 3, m2 = 5;
    // vector<vector<int>> nums1; 
    // vector<vector<int>> nums2;
    // nums1.push_back({3,4});
    // nums1.push_back({5,8});
    // nums2.push_back({1,3});
    // nums2.push_back({5,5});
    // nums2.push_back({7,9});
    Solution * solu = new Solution();
    int res = solu->findn(nums1, nums2);
    cout << res << endl;

}