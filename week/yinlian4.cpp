#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
按对查找，如果去掉交集之后两个列表都不为空，满足
*/

bool compare(vector<int> & a, vector<int> & b){
        return a[0] < b[0];
}

class Solution {
public:
    

    int coopDevelop(vector<vector<int>>& skills) {
        int n = skills.size();
        sort(skills.begin(), skills.end(), compare);
        int res = 0;
        int l = 0;
        while (l < n - 1)
        {
            int r = l + 1;
            while (r < n)
            {
                if(cooperate(skills[l], skills[r])){
                    res++;
                }
                r++;
            }
            l++;
        }
        return res;
    }

    bool cooperate(vector<int>& a, vector<int>& b){
        int m = a.size();
        int n = b.size();
        if(a[m - 1] < b[0]){
            return true;
        }
        // 计重复元素数量
        int repeatNum = 0;
        unordered_map<int, int> mp;
        if(m < n){
            for(int i = 0; i < m; i++){
                mp[a[i]]++;
            }
            for(int i = 0; i < n; i++){
                if(mp.count(b[i])){
                    repeatNum++;
                }
            }
        }else{
            for(int i = 0; i < n; i++){
                mp[b[i]]++;
            }
            for(int i = 0; i < m; i++){
                if(mp.count(a[i])){
                    repeatNum++;
                }
            }
        }
        if(repeatNum == m || repeatNum == n ){
            return false;
        }
        return true;
    }
};