#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <memory>

using namespace std;


/*
(()())
遍历是否有效的方法
从左到右，）的数量不能大于（


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        getBrackets(ans, "", 0, 0, n);

        return ans;
    }

    void getBrackets(vector<string> & brackets, string front,
    int left, int right, int n){
        if(right == n){
            brackets.push_back(front);
            return;
        }

        // 往front后面添加一个（ 或）
        if(right < left){
            getBrackets(brackets, front + ")", left, right + 1, n);
        }
        // 添加（， left + 1, n的值不变
        if(left < n){
            getBrackets(brackets, front + "(", left + 1, right, n);
        }


    }
};
*/

/*
思路二
任意括号组可以看作
(a)b
其中a和b为标准括号组，可以为空 长度都为偶数
因此上式中)的位置为 1+0+1 1+2+1 1+4+1
即 2 4 6 8...2*n
*/
class Solution{
    shared_ptr<vector<string>> cache[100] = {nullptr};
public:
    vector<string> generateParenthesis(int n){
        return *generate(n);
    } 

    shared_ptr <vector<string>> generate(int n){
        // 如果chchae[n]中已经存储，直接返回
        if(cache[n] != nullptr){
            return cache[n];
        }
        // cache中没有，开始构建
        // 为什么0要单独处理，因为else中已经有(a)b的假设，至少有一个()
        if(n == 0){
            cache[0] = shared_ptr<vector<string>>(new vector<string>{""});
        }else{
            auto result = shared_ptr<vector<string>>(new vector<string>);
            for(int i = 0; i < n; i++){
                // a的可能性, 0 ～ n-1个括号 是一个列表
                auto lefts = generate(i);
                // b的可能性 0 ～ n-1个括号
                auto rights = generate(n - 1 - i);
                for(const string& left : *lefts){
                    for(const string &right : *rights){
                        result -> push_back("(" + left + ")" + right);
                    }
                }
            }
            // 存入cache，方便下次调用
            cache[n] = result;
        }
        return cache[n];

    }
};


/*
思路三
使用()组装 
思想：string中必然存在一个()？
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if n == 1:
            return list({'()'})
        res = set()
        for i in self.generateParenthesis(n - 1):
            for j in range(len(i) + 2):
                res.add(i[0:j] + '()' + i[j:])
        return list(res)
*/

int main(){
    Solution * solu = new Solution();
    int n = 3;
    vector<string> res = solu->generateParenthesis(n);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << endl;
    }

}