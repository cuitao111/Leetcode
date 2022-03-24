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

/*
向右扩展范围时需要记录最大右值
*/

bool compare(const vector<int> & a, const vector<int> & b){
        return a[0] < b[0];
}

class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector<vector<int>>  res;
        int n = intervals.size();
        if(n == 1)
        {
            return intervals;
        }
        int l = 0, r = 0;
        int maxR = intervals[0][1];
        while (l < n)
        {
            // l表示需要整合的最左侧区间 r表示右侧
            if(r == n - 1){
                // 添加[l, r]
                maxR = max(maxR, intervals[r][1]);
                res.push_back({intervals[l][0], maxR});
                break;
            }
            if(intervals[r + 1][0] > maxR){
                // 如果
                res.push_back({intervals[l][0], maxR});
                l = r + 1;
                r = r + 1;
                maxR = intervals[l][1];
            }else{
                r++;
                maxR = max(maxR, intervals[r][1]);
                
            }
        }
        return res;
    }
};


int main(){
    Solution * solu = new Solution();
    vector<vector<int>> intervals;
    intervals.push_back({1,7});
    intervals.push_back({2,6});
    // intervals.push_back({8,10});
    // intervals.push_back({15,18});
    vector<vector<int>> res  = solu->merge(intervals);


}