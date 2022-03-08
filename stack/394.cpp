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
"a3[a2[c]a]"


栈
如果当前的字符为数位，解析出一个数字（连续的多个数位）并进栈
如果当前的字符为字母或者左括号，直接进栈
如果当前的字符为右括号，开始出栈，一直到左括号出栈，出栈序列反转后拼接成一个字符串，此时取出栈顶的数字（此时栈顶一定是数字，想想为什么？），就是这个字符串应该出现的次数，我们根据这个次数和字符串构造出新的字符串并进栈

递归
*/

class Solution {
public:
    string decodeString(string s) {

        int repeat = 0;
        stack<string> stk;
        stack<int> nums;
        string str;
        for(auto &ch : s){
            if(ch >= 'a' && ch <='z'){
                str.push_back(ch);
            }else if(ch >= '0' && ch <= '9'){
                repeat = repeat * 10 + int(ch - '0');
            }else if(ch == '['){
                stk.push(str);
                nums.push(repeat);
                repeat = 0;
                str.clear();
            }else{
                int times = nums.top();
                nums.pop();
                string fstr = stk.top();
                stk.pop();
                // 遇到]
                for(int i = 0; i < times; i++){
                    fstr += str;
                }
                // repeat归0
                str = fstr;
            }
        }
        return str;
        
    }
};

int main(){
    Solution * solu = new Solution();
    string s = "a3[a2[c]a]c";
    string res = solu->decodeString(s);
    cout << res <<endl;
}