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
参议员可以让另一位参议员在这一轮和随后的几轮中丧失所有的权利
从队列里排除，给每个位置设置一个flag 若为-1，跳过
阵营
假设每一位参议员都足够聪明，把后面最近的一个不同阵营禁言
用两个队列把R和D的位置分别保存
每次决定的是两个队列头部index较小的，
禁言过程就是把另一个队列头部的flag设为-1
胜利条件判断，有一个队列为空

错误用例：
"RDD" 
R: 0
D: 1 2
正确顺序：R0禁D1 D2禁言R0
实际调用: R0禁D1 R0禁D2 因为R.front永远小于Dfront
解决,每个元素后跟一个轮数 优先判断轮数再判断index大小
*/

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<pair<int, int>> Radiantq;
        queue<pair<int, int>> Direq;
        for(int i = 0; i < senate.length(); i++){
            if(senate[i] == 'R'){
                Radiantq.emplace(i, 1);
            }else{
                // 非R即D
                Direq.emplace(i, 1);
            }
        }
        while (!Radiantq.empty() && !Direq.empty())
        {
            int roundsOfR = Radiantq.front().second;
            int roundsOfD = Direq.front().second;
            int indexOfR = Radiantq.front().first;
            int indexOfD = Direq.front().first;
            if(roundsOfR < roundsOfD || (roundsOfR == roundsOfD && 
            indexOfR < indexOfD)){
                Direq.pop();
                // R应转移到队尾进行下一次轮换
                Radiantq.pop();
                Radiantq.emplace(indexOfR, roundsOfR + 1);
            }else{
                Direq.pop();
                // R应转移到队尾进行下一次轮换
                Radiantq.pop();
                Direq.emplace(indexOfD, roundsOfD + 1);
            }
        }
        return Radiantq.empty() ? "Dire" : "Radiant";
        
    }
};

int main(){
    Solution * solu = new Solution();
    string senate = "RDD";
    string res = solu->predictPartyVictory(senate);
}