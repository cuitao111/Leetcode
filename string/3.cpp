#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sizeOfS = s.length();
        // 存位置 or 数量
        unordered_set<char> occ;
        // 定义两个指针
        int right = 0;
        int maxLen = 0;

        for(int i = 0; i < sizeOfS; i++){
            if(i != 0){
                occ.erase(s[i - 1]);
            }
            // 一直右移，直到找到重复的字符
            while(!occ.count(s[right]) && right < sizeOfS){
                occ.insert(s[right]);
                right++;
            }

            maxLen = max(maxLen, right - i);
            

        }
        return maxLen;
        

    }
};


int main(){
    Solution * solu = new Solution();
    string s = "abcabcbb";
    int res = solu->lengthOfLongestSubstring(s);
    cout << res << endl;
}