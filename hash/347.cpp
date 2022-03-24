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
    static bool cmp(pair<int, int> & m, pair<int, int> & n){
        // 按value也就是次数从大到小排列
        return m.second > n.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        // 找出mp中second前k个最大值
        // priority_queue<pair<int,int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
        for(auto & [num, count] : mp){
            if(q.size() == k){
                if(q.top().second < count){
                    q.pop();
                    q.emplace(num, count);
                }
            }else{
                 q.emplace(num, count);
            }
        }
        vector<int> ret;
        while (!q.empty()){
            ret.emplace_back(q.top().first);
            q.pop();
        }
        return ret;
        
    }
};