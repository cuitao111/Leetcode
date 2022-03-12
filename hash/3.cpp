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
只需要输出最长数字
只需要set
不断递增左边界，查找最长子串
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        unordered_set<char> set;
        int rk = -1;
        for(int i = 0; i < s.length(); i++){
            // 当更换开头时，需要将旧元素剔除
            if(i != 0){
                set.erase(s[i - 1]);
            }

            while (rk + 1 < s.size() && !set.count(s[rk + 1]))
            {
                rk++;
                set.insert(s[rk]);
            }
            maxLen = max(maxLen, rk - i + 1);
            
        }
        return maxLen;

    }
};