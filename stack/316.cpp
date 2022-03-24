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
如何使用栈
用map保存<char,位置>？
当两个重复的之间有小的字典序 删除前面
全部为大序 删除后面

需保证 返回结果的字典序最小
当遇到重复的字母删除哪一个

需要记录每个字符是否出现在栈中
需要记录每个字符的剩余数量
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> vis(26), nums(26);
        // vis用于存储栈中是否还存在元素
        // nums用于保存后续还有多少个字母
        // 使用26长度的vector来代表26个字母
        for(auto &ch : s){
            nums[ch - 'a']++;
        }
        string stk;
        for(auto & ch : s){
            // 如果栈不为空，则陆续弹出栈顶大于ch的元素
            // 弹出时需要检测是否还存在可以入栈的数量
            if(!vis[ch - 'a']){
                // 如果栈中无该元素,考虑入栈
                while (!stk.empty() && stk.back() > ch)
                {
                    // 当不为空且顶部元素大于ch
                    // 再考虑是否后续还有相同的元素
                    if(nums[stk.back() - 'a'] > 0){
                        // 出栈,同时改变vis表示没有访问过
                        vis[stk.back()- 'a'] = 0;
                        stk.pop_back();
                    }else{
                        break;
                    }
                }
                // ch入栈
                vis[ch -'a'] = 1;
                stk.push_back(ch);
                
            }
            nums[ch - 'a']--;
        }
        return stk;

    }
};