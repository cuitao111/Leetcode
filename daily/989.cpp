#include <iostream>
#include <vector>
#include <stack>
using namespace std;



class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        int carry = 0;
        int i = n - 1;
        stack<int> stk;
        
        while(i >= 0){
            int sum = num[i] + k % 10 + carry;
            carry = sum / 10;
            stk.push(sum % 10);
            k /= 10;
            i--;
        }

        while( k != 0){
            int sum = k % 10 + carry;
            carry = sum / 10;
            stk.push(sum % 10);
            k /= 10;
        }
        if(carry != 0){
            stk.push(carry);
        }
        vector<int> res;
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
};

int main(){
    Solution * solu = new Solution();
    vector<int> num{1,2,0,0};
    int k = 34;
    vector<int> res = solu->addToArrayForm(num, k);
    

}