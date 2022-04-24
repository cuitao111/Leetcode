#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        //从右上角开始
        int m = matrix.size();
        if(m == 0){
            return false;
        }
        int n = matrix[0].size();
        int i = 0, j = n - 1;
        while(i < m && j >= 0){
            // 如果等于target
            if(matrix[i][j] == target){
                return true;
            }else if(matrix[i][j] < target){
                // 去掉所在行，值都比[i][j]小
                i++;
            }else{
                // 如果target小，向左找
                j--;
            }
        }
        return false;
    }
};


int main(){
    Solution * solu = new Solution();
    vector<vector<int>> matrix;
    matrix.push_back(vector<int>{1,4,7,11,15});
    matrix.push_back(vector<int>{2,5,8,12,19});
    matrix.push_back(vector<int>{3,6,9,16,22});
    matrix.push_back(vector<int>{10,13,14,17,24});
    matrix.push_back(vector<int>{18,21,23,26,30});
    bool res = solu->findNumberIn2DArray(matrix, 5);
    cout <<res << endl;
    cin.get();


}