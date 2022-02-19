#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <memory>

using namespace std;

/*
有效字符串应该保证，右括号数量小于等于左括号数量
且左括号数量与右括号相等
1、先删除非合法的右括号数，同时计数 左右数量 删除的不计入
2、删除多余的左括号

字母位置不影响，判断是否在a - z间即可

若更改为返回所有的合法字符串？
*/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int left = 0, right = 0;
        string ans;
        // 遍历数组
        for(int i = 0; i < s.length(); i++){
            // 如果遇到非合法右括号
            if(right == left && s[i] == ')'){
                continue;
            }
            // 遇到合法的左括号，添加并增加left
            if(s[i] == '('){
                ans.push_back(s[i]);
                left++;
            }
            // 遇到合法的右括号，增加right
            if(s[i] == ')'){
                ans.push_back(s[i]);
                right++;
            }

            if(s[i] >= 'a' && s[i] <= 'z'){
                ans.push_back(s[i]);
            }

        }
        // 删除left - right个'('
        // 从右向左删除
        if(left > right){
            int restOfl = left - right;
            for(int i = ans.size() - 1; i >= 0; i--){
                if(restOfl == 0){
                    break;
                }
                if(ans[i] == '('){
                    ans.erase(i, 1);
                    restOfl--;
                }
            }
        }
        return ans;
    }
};


int main(){
    Solution * solu = new Solution();
    string s = "lee(t(c)o)de)";
    string res = solu->minRemoveToMakeValid(s);
    cout << res << endl;

}