#include <iostream>
#include <vector>

using namespace std;

/*
从1-n加入sum
*/
class Solution{
    vector<vector<int>> resNums;
public:
    void backstrack(vector<int> & res, int k, int i, int sum, int x){
        if(sum == x){
            resNums.push_back(res);
        }
        if(i > k){
            // i到末尾
            return;
        }
        if(sum + i > x){
            // 剪枝条
            return;
        }
        // 两种选择，不加i
        backstrack(res, k, i + 1, sum, x);
        res.push_back(i);
        backstrack(res, k, i + 1, sum+i, x);
    }

    vector<vector<int>> getNums(int n, int k, int x){
        vector<int> res;
        backstrack(res, k, 1, 0, x);
        return resNums;
    }
};



int main(){
    // int n,k,x;
    // cin >> n >> k >> x;
    Solution * solu = new Solution();
    vector<vector<int>> res = solu->getNums(2, 2, 2);
    if(res.size() == 0){
        cout << -1 << endl;
    }else{
        for(int i = 0; i < res[0].size(); i++){
            cout << res[0][i] << " ";
        }
    }

}