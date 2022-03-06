#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int columns = matrix[0].size();
        int rows = matrix.size();
        if( columns == 0 || rows == 0){
            return false;
        }
        bool found = false;
        // 从右上角开始 [0][columns - 1]
        int row = 0;
        int column = columns -1;
        while(row < rows && column >= 0){
            if(matrix[row][column] == target){
                // 找到则将found设置为true，并退出循环
                found = true;
                break;
            }else if(matrix[row][column] > target){
                // 列减1
                column--;
            }else{
                // 行加1
                row++;
            }
        }
        return found;
    }
};


int main(){
    Solution * solu = new Solution();

}