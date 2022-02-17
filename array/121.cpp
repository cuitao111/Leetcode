#include <iostream>
#include <vector>
#include <unordered_map>
#include<algorithm>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sizeOfPrice = prices.size();
        // 返回值
        int ans = 0;
        int minPrice = prices[0];
        int maxProfit = 0;
        for(int i = 0; i < sizeOfPrice; i++){
            maxProfit = max(maxProfit, prices[i] - minPrice);
            if(prices[i] < minPrice){
                minPrice = prices[i];
            }
        }
        return maxProfit;
    }
};

int main(){
    Solution * solut = new Solution();
    vector<int> prices{7,1,5,3,6,4};
    int res = solut->maxProfit(prices);
    cout << res << endl;
}