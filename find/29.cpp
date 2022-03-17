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
    int getProduct(int x, int n){
        if( n == 0){
            return 0;
        }
        int halfRes = getProduct(x, n / 2);
        if(n % 2 == 0){
            return halfRes + halfRes;
        }else{
            return halfRes + halfRes + x;
        }
    }

    int divide(int dividend, int divisor) {
        // 需要改为-|dividend| ~|dividend
        int left = 0, right = dividend;
        while (left < dividend)
        {
            int mid = (left + right) / 2;
            int product = getProduct(mid , divisor);
            int product_1 = getProduct(mid + 1 , divisor);
            if(product < dividend && product_1 > dividend){
                return mid;
            }
            if(product > dividend){
                // 结果在右侧
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return left;
        
    }
};

int main(){
    Solution * solu = new Solution();
    int dividend = 10, divisor = 3;
    int res = solu->divide(dividend, divisor);
    cout << res << endl;
}