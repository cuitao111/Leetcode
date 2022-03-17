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
二分思想
将n拆分为两个 n/2

*/

class Solution {
public:
    double myPow(double x, int n) {
        long long m = n > 0 ? n : -n;
        if(n == 0){
            return 1;
        }
        if(n == 1){
            return x;
        }
        double res;
        double half  = myPow(x, m / 2);
        if(n % 2 == 0){
            
            res = half * half;
        }else{
            res = half * half * x;
        }
        return n > 0 ? res : (1.0 / res);

    }
};