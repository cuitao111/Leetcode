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
暴力思路：每次向右遍历一遍，找到小于该位置的数量
二分：
counts[0] = counts[1] + 1;
counts[1] = counts[3] + 1;
counts[2] = counts[3] + 1;
counts[3] = 0;最右侧永远为0

*/

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        
    }
};
