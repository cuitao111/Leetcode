#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        int l = 0, t = 0, r = n - 1, b = m - 1;
        while(l <= r&& t <= b){
            for(int i = l; i <= r; i++){
                res.push_back(matrix[t][i]);
            }
            for(int i = t + 1; i <= b; i++){
                res.push_back(matrix[i][r]);
            }
            if(t < b && l < r){
                // 右向左
                for(int i = r - 1; i >= l; i--){
                    res.push_back(matrix[b][i]);
                }
                for(int i = b - 1; i > t; i--){
                    res.push_back(matrix[i][l]);
                }
            }
            l++;
            r--;
            t++;
            b--;
        }
        return res;

    }
};

int main(){
    Solution * solu = new Solution();
    vector<vector<int>> matrix;
    vector<int> a{1};
    vector<int> b{4};
    vector<int> c{7};
    matrix.push_back(a);
    matrix.push_back(b);
    matrix.push_back(c);
    vector<int> res = solu->spiralOrder(matrix);
    cout << 1 << endl;


}