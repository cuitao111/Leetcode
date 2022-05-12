#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        if(n == 0){
            return true;
        }
        stack<int> stk;
        int pop_i = 0;
        for(int i = 0; i < n; i++){
            stk.push(pushed[i]);
            while(!stk.empty() && stk.top() == popped[pop_i]){
                stk.pop();
                pop_i++;
            }
        }
        return stk.empty() ? true : false;
    }
};



int main(){
    Solution * solu = new Solution();
    vector<int> pushed{1,2,3,4,5};
    vector<int> popped{4,5,3,2,1};
    bool res = solu->validateStackSequences(pushed, popped);
    cin.get();

}