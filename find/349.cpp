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


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int p1 = 0, p2 = 0;
        unordered_map<int, int> set;
        while(p1 < nums1.size() && p2 < nums2.size())
        {
            if(nums1[p1] == nums2[p2]){
                set[nums1[p1]]++;
                p1++;
                p2++;
            }else if(nums1[p1] > nums2[p2]){
                p2++;
            }else{
                p1++;
            }
        }
        vector<int> res;
        for(auto & it : set){
            res.push_back(it.first);
        }
        return res;
    }
};

int main(){
    Solution * solu = new Solution();
    vector<int> nums1{1,2,2,1};
    vector<int> nums2{2};
    vector<int> res = solu->intersection(nums1, nums2);
}