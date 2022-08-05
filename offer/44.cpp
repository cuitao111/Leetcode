#include <iostream>
#include <math.h>
#include <vector>

using namespace std;


class Solution {
public:
    int findNthDigit(int n) {
        // 先判断所在的数字数位
        int i = 0;
        int sum_digital = 0;
        while(n >= sum_digital){
            //先减去上一位的总位数
            n -= sum_digital;
            // 按个十百计算当前总位数 个位 9 * 1 * 10^
            sum_digital = 9 * (i + 1) * pow(10, i);
            // 
            i++;
        }
        // 再判断数字的值
        int cur_val;
        if(i == 1){
            cur_val = (n - 1);
        }else{
            cur_val = (n - 1) / i + pow(10, i - 1);
        }
        // 判断在数字的哪一位,以及值
        // 在cur_val的哪一位
        int inter_dig = (n - 1) % i;
        return int(cur_val / pow(10, i - inter_dig)) % 10;
    }
};


int main(){
    Solution * solu = new Solution();
    cout << solu->findNthDigit(3);
}