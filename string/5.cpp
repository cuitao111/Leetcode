#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;

/*
从左到右遍历数组，找到第i处为左边界的回文字
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int sizeOfS = s.length();
        if(sizeOfS  < 2){
            return s;
        }

        int maxLen = 1;
        int begin = 0;
        
        vector<vector<bool>> dp(sizeOfS, vector<bool>(sizeOfS, false));

        for(int i = 0; i < sizeOfS; i++){
            dp[i][i] = true;
        }
        // 从长度为2开始遍历
        for(int L = 2; L <= sizeOfS; L++){
            for(int i = 0; i < sizeOfS; i++){
                // 计算字符串末尾
                // i=0 L=2 j=1 L+i-1
                int j =  L + i - 1;
                // 判断j是否越界
                if(j >= sizeOfS){
                    break;
                }
                // 如果开始和末尾不同，设置为false
                if(s[i] != s[j]){
                    dp[i][j] = false;
                    continue;
                }
                // i和j处字符相同
                // 根据内部字符串的真假判断
                if(j - i < 3){
                    dp[i][j] = true;
                }else if(dp[i + 1][j - 1])
                {
                    dp[i][j] = true;
                }

                if(dp[i][j] && j - i + 1 > maxLen){
                    // 如果回文串长度大于maxLen,更新begin maxLen
                    begin = i;
                    maxLen = j - i + 1;
                }


            }
        }
        return s.substr(begin, maxLen);
    }
};

int main(){
    Solution * solu = new Solution();
    string s = "babad";
    string res = solu->longestPalindrome(s);
    cout << res << endl;

}