#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        int sizeOfLog = logs.size();
        // 设置数粗存储标识府
        vector<string> letterList;
        vector<string> digList;

        // 遍历数组分类
        for(int i = 0; i < sizeOfLog; i++){
            int pos = logs[i].find(" ");
            char ch = logs[i][pos + 1];
            if(ch >= '0' && ch <= '9'){
                digList.push_back(logs[i]);
            }else{
                letterList.push_back(logs[i]);
            }
        }

        // 排序字母数字
        sort(letterList.begin(), letterList.end(), cmp);

        vector<string> res;
        for(int i = 0; i < letterList.size(); i++){
            res.push_back(letterList[i]);
        }
        for(int i = 0; i < digList.size(); i++){
            res.push_back(digList[i]);
        }
        return res;
        
        

    }

    static bool cmp(string a, string b){
        int pos1 = a.find(" ");
        int pos2 = b.find(" ");

        // substr第二个参数为空直接到末尾
        if(a.substr(pos1 + 1) == b.substr(pos2 + 1)){
            return a.substr(0, pos1) < b.substr(0, pos2);
        }else{
            return a.substr(pos1 + 1) < b.substr(pos2 + 1);
        }
    }


};

int main(){

}