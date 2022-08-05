#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int test(int n){
        vector<vector<int>> dp(n+1, vector<int>(2));
        dp[1][0] = 1;
        dp[2][0] = 1;
        dp[2][1] = 1;
        dp[3][0] = 2;
        dp[3][1] = 2;

        for(int i = 4; i < n + 1; i++){
            dp[i][0] = dp[i - 1][0] + dp[n-1][1];
            if(i > 3){
                dp[i][1] = dp[n - 2][0] + dp[n - 2][0] + dp[n - 3][0]; 
            }
            
        }

        return dp[n][0] + dp[n][1];
    }
};


int main(){
    Solution * solu = new Solution();
    cout << solu->test(4);
    cin.get();
    return 0;
}