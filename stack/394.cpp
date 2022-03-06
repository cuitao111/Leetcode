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

/*
遇到字母直接输出，遇到数字之后开始保存sum  sum*10 + i
遇到[ 开始维护一个str 直到] 重复 sum 次 重复完毕sum归0
str.clear

*/

class Solution {
public:
    string decodeString(string s) {
        string res;

        int repeat = 0;
        stack<string> stk;
        string str;
        for(auto &ch : s){
            if(ch >= 'a' && ch <='z'){
                if(repeat != 0){
                    str.push_back(ch);
                }else{
                    res.push_back(ch);
                }  
            }else if(ch >= '0' && ch <= '9'){
                repeat = repeat * 10 + int(ch - '0');
            }else if(ch == '['){
                continue;
            }else{
                // 遇到]
                for(int i = 0; i < repeat; i++){
                    res += str;
                }
                // repeat归0
                repeat = 0;
                str.clear();
            }
            
            
        }
        return res;
        
    }
};

int main(){
    Solution * solu = new Solution();
    string s = "3[a]2[bc]";
    string res = solu->decodeString(s);
    cout << res <<endl;
}