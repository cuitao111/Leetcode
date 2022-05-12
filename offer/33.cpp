#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        int n = postorder.size();
        if(n == 1) return true;
        return verifysubTree(postorder, 0, n - 1);
    }

    bool verifysubTree(vector<int>& postorder, int l, int r){
        if(l == r){
            return true;
        }
        // 找到第一个大于r的值
        int i = l;
        for(; i <= r - 1; i++){
            if(postorder[i] > postorder[r]){
                break;
            }
        }
        for(int j = i ; j <= r - 1; j++){
            if(postorder[j] < postorder[r]){
                return false;
            }
        }

        // i == l 没有左子树，
        bool res = true;
        if(i > l) res = res && verifysubTree(postorder, l, i - 1);
        if(i < r) res = res && verifysubTree(postorder, i, r - 1);
        return res;
    }
};

int main(){
    vector<int> postorder{1,2,5,10,6,9,4,3};
    Solution * solu = new Solution();
    bool res = solu->verifyPostorder(postorder);
    cin.get();
}