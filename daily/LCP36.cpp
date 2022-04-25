#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
排序后需要找出数组中
找到了满足条件的三个数，判断是否要将其加入最后的结果
dp[i]: 前i个元素能组成的最多的牌组
dp[0] = dp[1] = dp[2] = 0 
dp[i + 1] :先找出 dp[i]中最后两个元素
*/

class Solution {
public:
    int maxGroupNumber(vector<int>& tiles) {
        sort(tiles.begin(),tiles.end());
    }
};

int main(){


}