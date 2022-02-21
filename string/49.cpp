#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <memory>

using namespace std;

/*
分组
每个词设定一个值，是否遍历过
栈
每次取一个a，跟后续b比较
比较方法：
1、遍历a的所有组合形式，若单词太常耗时耗空间
2、遍历b的每个单词，从a中寻找，若找不到说明不是
，根据题意，通常恰好只出现一次,测试用例中有重复情况

栈
源单词进栈
向后遍历数组，找到所有异位词
弹出
并标记visited

允许存在相同的元素
和空字符串

超出时间限制





class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int sizeOfStrs = strs.size();
        vector<vector<string>> ans;
        // 0或1个元素
        if(sizeOfStrs == 0 || sizeOfStrs == 1){
            ans.push_back(strs);
            return ans;
        }
        // 定义栈
        stack<string>  stk;
        // 定义一个遍历数组
        vector<bool> visited(sizeOfStrs, false);

        for(int i = 0; i < sizeOfStrs; i++){
            if(!visited[i]){
                stk.push(strs[i]);
                visited[i] = true;
                // 加一个空字符串判定
                if(strs[i] == ""){
                    for(int j = i + 1; j < sizeOfStrs; j++){
                        // 若为空，压入栈并设置访问标志
                        if(!visited[j] && strs[j] == ""){
                            stk.push(strs[j]);
                            visited[j] = true;
                        }
                    }
                }else{
                    unordered_map<char, int> sourceMap;
                    for(int k = 0; k < strs[i].length();k++){
                        if(sourceMap[strs[i][k]]++);
                    }

                    // 向后遍历
                    for(int j = i + 1; j < sizeOfStrs; j++){
                        if(visited[j] || strs[i].length() != strs[j].length()){
                            // 若遍历过或长度不等直接下一个
                            continue;
                        }
                        unordered_map<char, int> chmap = sourceMap;
                        // 比较strs[i] 和 strs[j]
                        int k = 0;
                        for(k = 0; k < strs[j].length(); k++){
                            if(chmap.count(strs[j][k]) > 0 && 
                            chmap[strs[j][k]] > 0){
                                // 找到了字符,且还有可以富裕量
                                chmap[strs[j][k]]--;
                            }else{
                                // 匹配失败
                                break;
                            }
                        }
                        // 如果全部匹配完成，遍历标志设置为true，压入stk
                        if(k == strs[j].length()){
                            stk.push(strs[j]);
                            visited[j] = true;
                        }
                    }
                }
                
                vector<string> groupStr;
                // 与源词比较完成，所有元素出栈
                while(!stk.empty()){
                    string s= stk.top();
                    groupStr.push_back(s);
                    stk.pop();
                }
                ans.push_back(groupStr);
            }
        }
        return ans;

    }
};

思路二：
找异位单词的相同之处
将它们重新排列之后相同，对应的26个字母组成的频次表也相同
woshicaib
*/

class Solution{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // <源单词， 对应列表>
        unordered_map<string, vector<string>> mp;
        for(string& str : strs){
            string key = str;
            // 排序
            sort(key.begin(), key.end());
            // key对应的value 添加str
            mp[key].emplace_back(str);
        }
        vector<vector<string>> ans;
        for(auto it = mp.begin(); it != mp.end(); it++){
            ans.emplace_back(it->second);
        }
        return ans;
    }
};



int main(){
    Solution * solu = new Solution();
    // vector<string> strs{"ddddddddddg","dgggggggggg"};
    // vector<string> strs{"","b",""};
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    
    vector<vector<string>> res = solu->groupAnagrams(strs);
    cout << 1 << endl;

}