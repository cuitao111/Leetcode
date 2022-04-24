#include <iostream>

using namespace std;


class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0){
            // 当x==0 位于分母时也返回0
            return 0;
        }
        long long N = n;
        if(n >= 0){
            return getPow(x, N);
        }else{
            return 1.0 / getPow(x, -N);
        }
    }


    double getPow(double x, long long n){
        if(n == 1){
            return x;
        }
        if(n == 0){
            return 1;
        }
        double half_res = getPow(x , n >> 1);
        double res = half_res * half_res;
        if(n & 0x1 == 1){
            // 指数奇数额外乘一次x
            return res*x;
        }
        return res;
    }
};