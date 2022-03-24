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
找到第一个不重复的字符,需要遍历完数组
用vector(26)存储出现的次数
队列具有「先进先出」的性质，因此很适合用来找出第一个满足某个条件的元素。

使用队列难点：
遇到baab的情况
在第二次遇到a时由于队首为b无法弹出，因此第一个a也无法弹出
因此需要用map来标记a这样当遇到第二个b时
就可以根据标记来一直弹出直到遇到不重复的字符

*/

class Solution {
public:
    int firstUniqChar(string s) {
        // 记录第一次出现的位置
        unordered_map<char, int> position;
        queue<pair<char,int>> q;
        for(int i = 0; i < s.length(); i++){
            // 如果没有找到记录
            // 如果之前有不需要
            if(!position.count(s[i])){
                position[s[i]] = i;
                q.emplace(s[i],i);
            }else{
                // 如果之前遇到将positon改为-1
                // 从头部排出重复字符
                position[s[i]] = -1;
                while (!q.empty() && position[q.front().first] == -1)
                {
                    q.pop();
                }
                
            }

            
        }
        return q.empty() ? -1 : q.front().second;
    }
    
};

int main(){
    Solution * solu = new Solution();
    string s = "loveleetcode";
    int res = solu->firstUniqChar(s);

}