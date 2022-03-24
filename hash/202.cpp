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
用mp.count()作为循环退出条件
最后返回 n == 1
*/

class Solution {
public:
    unordered_map<int, int> mp;

    int getSquare(int n ){
        int sum = 0;
        while(n / 10 != 0){
            sum += (n % 10) *  (n % 10);
            n /= 10;
        }
        if(n != 0){
            sum += n * n;
        }
        return sum;
    }

    bool isHappy(int n) {

        int v = getSquare(n);
        if(v == 1){
            return true;
        }
        if(mp.count(n)){
            return false;
        }
        mp[n] = v;
        return isHappy(v);
    }
};