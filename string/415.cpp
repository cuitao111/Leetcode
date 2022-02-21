#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <memory>

using namespace std;

/*
官方解答虽然简洁，逻辑处理统一，
但是没有做提前结束的判断，想象一个极端case，
比如num1很长很长，而num2很短，
这时如果num2已经遍历完且进位数字也为0的时候就不用再循环了，
这会节省很多循环中的操作
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.length(), len2 = num2.length();
        int minlen = min(len1, len2);
        // 从个位往前推
        string ans;
        int innum = 0;
        for(int i = 1; i <= minlen; i++){
            int char1 = num1[len1 - i] - 48;
            int char2 = num2[len2 - i] - 48;
            int sum = char1 + char2 + innum;
            innum = sum / 10;
            // innum会影响sum的值所以设置变量维护
            ans = ans + (char)(sum % 10 + 48);
        }
        if(len1 > len2){
            for(int i = len1 - len2 - 1; i >=0; i--){
                int char1 = num1[i] - 48;
                int sum =  char1 + innum;
                innum = sum / 10;
                ans = ans + (char)(sum % 10 + 48);
            }
        }else if(len2 > len1){
            for(int i = len2 - len1 - 1; i >=0; i--){
                int char2 = num2[i] - 48;
                int sum = char2 + innum;
                innum = sum / 10;
                ans = ans + (char)(sum % 10 + 48);
            }
        }
        if(innum !=  0){
            ans = ans + (char) (innum + 48);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    Solution * solu = new Solution();
    string num1 = "456";
    string num2 = "77";
    string res = solu->addStrings(num1, num2);
    cout << res << endl;

}