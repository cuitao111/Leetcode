#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
每次找出数组中的最大值进行投资
先排序 sort默认升序
投资玩一次后该位置减1

不提供sort 排序算法
当nums中同时有n个最大值，需要把他们都投资一遍再往前找较小的值

*/

class Solution {
public:
    int maxInvestment(vector<int>& product, int limit) {
        long res = 0;
        int n = product.size();
        sort(product.begin(), product.end());
        int maxNums = 1;
        for(int i = n - 1; i > 0; i--){
            int maxProduct = product[i];
            while (limit > 0 && maxProduct > product[i - 1])
            {
                if(limit >= maxNums){
                    //maxNums个最大值都投资一遍
                    res += (long)maxNums * maxProduct;
                    limit -= maxNums;
                    maxProduct--;
                }else{
                    // 投资limit个maxProduct
                    res += (long)limit * maxProduct;
                    limit = 0;
                }
            }
            if(limit > 0){
                // 此时最大值变为product[i - 1] 数量多一个
                maxNums++;
            }else{
                break;
            }
            
        }
        if(limit != 0){
            // 如果此时还需要投资nums中的值全部为最小值
            int maxProduct = product[0];
            while (limit > 0 && maxProduct > 0)
            {
                if(limit >= maxNums){
                    //maxNums个最大值都投资一遍
                    res +=(long) maxNums * maxProduct;
                    limit -= maxNums;
                    maxProduct--;
                }else{
                    // 投资limit个maxProduct
                    res +=(long) limit * maxProduct;
                    limit = 0;
                }
            }
        }
        return res % 1000000007;
    }
};


int main(){
    Solution * solu = new Solution();
    vector<int> product{4,5,3};
    cout << solu->maxInvestment(product, 8);
    cin.get();
}
