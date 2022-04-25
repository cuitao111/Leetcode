#include <iostream>
#include <vector>
using namespace std;



int main(){
    Solution * solu  = new Solution();
    int n = 2;
    vector<int> res = solu->printNumbers(n);
    cin.get();
}

class Solution {
public:
vector<int> output;
    vector<int> printNumbers(int n) {
        if(n < 0){
            return vector<int>(0);
        }
        // 定义一个长度为n的字符串
        string s(n, '0');
        // 只要没有越界，就往output中添加s对应的数字
        while(!overflow(s)){
            inputNums(s);
        }
        return output;
    }

    bool overflow(string &s){
        // 进位
        int carry = 0;
        for(int i = s.length() - 1; i >=0; i--){
            int cur = s[i] - '0' + carry;
            // 个位才++
            if(i == s.length() - 1){
                cur++;
            }
            if(cur >= 10){
                // 进位
                if(i == 0){
                    // 已经为最高位，越界
                    return true;
                }else{
                    s[i] = cur - 10 + '0';
                    carry = 1;
                }
            }else{
                // 没有进位，更新i位置的值
                s[i] = cur + '0';
                return false;
            }
        }

        return false;
    }

    void inputNums(string &s){
        // 将s转换为int存入output
        // 
        int zero_flag = false;
        // 将前置0去掉之后存入res
        string res = "";
        for(int i = 0; i < s.length(); i++){
            if(!zero_flag && s[i] != '0'){
                // 遇到第一个非0 的数
                zero_flag = true;
            }
            if(zero_flag){
                res.push_back(s[i]);
            }
        }

        output.push_back(stoi(res));
    }


};