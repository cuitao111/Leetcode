#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <memory>
#include <queue>
#include <list>
#include <numeric>

using namespace std;


const unordered_map<char, string> value
{
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};

class Solution {
public:
    void backstrack(vector<string> & res,  string s, int i, string digits){
        if(i ==digits.length()){
            res.push_back(s);
            return;
        }
        // 如果不到末尾需要提取digist的第i位并循环拼拼接到后面
        string str  = value.at(digits[i]);
        for(int j = 0; j < str.size(); j++){
            
            backstrack(res, s + str[j], i + 1, digits);
        }
        
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.length() == 0){
            return res;
        }
       
        string combination;
        backstrack(res, combination, 0, digits);
        return res;
    }
};


int main(){
    Solution * solu = new Solution();
    string digits = "23";
    vector<string> res = solu->letterCombinations(digits);

}