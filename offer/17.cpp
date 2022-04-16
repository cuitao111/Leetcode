#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
vector<int> output;
    vector<int> printNumbers(int n) {
        // 创建长为n的string
        if(n < 0){
            return vector<int>(0);
        }
        string str(n, '0');
        while (!overflow(str))    
        {
            inputNums(str);
        }
        return output;
    }

    bool overflow(string & s){
        int inNum = 0;
        bool overflag = false;
        for(int i = s.length() - 1;i >= 0; i--){
            // 获取当前数位
            int cur = s[i] - '0' + inNum;
            if(i == s.length() - 1) {
                // 个位才++
                cur++;
            }
            if(cur >= 10){
                // 发生进位，判断是否越界
                if(i == 0){
                    return true;
                }else{
                    inNum = cur / 10;
                    s[i] = (cur % 10) + '0';
                }
            }else{
                // 没有发生进位，更新i位后可以直接返回
                s[i] = cur + '0';
                break;
            }
        }
        return overflag;
    }

    void inputNums(string &s){

        int flag = false;
        string res = "";
        for(int i = 0; i < s.length(); i++){
            if(!flag && s[i] != 0){
                // 遇到了第一个非0
                flag = true;
            }
            if(flag){
                res.push_back(s[i]);
            }
        }

        output.push_back(stoi(res));
    }
};

int main(){
    Solution * solu  = new Solution();
    int n = 2;
    vector<int> res = solu->printNumbers(n);
    cin.get();
}