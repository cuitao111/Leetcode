#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <memory>
#include <queue>

using namespace std;


class Solution {
    unordered_map<int, int> mp;
public:
    int numTrees(int n) {
        // 先从map里面找
        if(mp.count(n)){
            return mp[n];
        }
        if(n == 0 || n == 1){
            return 1;
        }
        int sum = 0;
        for(int i = 0; i < n; i++){
            int left = numTrees(i);
            int right = numTrees(n - 1 - i);
            sum += left * right;
        }
        mp[n] =  sum;
        return sum;
    }
};

int main(){
    Solution * solu = new Solution();
    int res = solu->numTrees(3);
    cout << res << endl;
}