#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int fib(int n){
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        int fn_1 = 0, fn_2 = 0;
        int sum = 1;
        for(int i = 2; i <= n; i++){
            fn_2 = fn_1;
            fn_1 = sum;
            sum = (fn_1 + fn_2) % 1000000007;
        }
        return sum;
    }
};