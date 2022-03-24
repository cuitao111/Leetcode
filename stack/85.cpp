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

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // 先判断为空的情况
        int rows = matrix.size();
        if(rows == 0){
            return 0;
        }
        int cloumns = matrix[0].size();

        vector<vector<int>> left(rows, vector<int>(cloumns, 0));
        // 构造柱形图
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cloumns; j++){
                if(matrix[i][j] == '1'){
                    left[i][j] = (j==0 ? 0 : left[i][j - 1]) + 1;
                }
            }
        }

        stack<int> stk;
        int maxArea = 0;
        for(int j = 0; j < cloumns; j++){
            // 每一列作为底部
            vector<int> up(rows), down(rows);
            // 从上到下遍历一变柱状图
            for(int i = 0; i < rows; i++){
                // 当遇到大于栈顶的i时弹出
                // 找到最近的小于i高度的位置
                while(!stk.empty() && left[stk.top()][j] > left[i][j]){
                    int topi = stk.top();
                    stk.pop();
                    // 弹出元素时，说明i高度小于topi,i可以作为下边界
                    down[topi] = i;
                }
                if(stk.empty()){
                    // 栈为空，说明达到上边界
                    up[i] =  -1;
                }else{
                    // 否则，上边界为栈顶元素
                    up[i] = stk.top();
                }
                stk.push(i);
            }
            while (!stk.empty())
            {
                // 栈内部还有元素，for循环最后一部一定是压入最右侧元素
                // 此时站内为单调，都能他达到下边界
                down[stk.top()] = rows;
                stk.pop();
            }
            // 从上到下遍历一边，找到最大矩形
            for(int i = 0; i < rows; i++){
                int bottom = down[i] - up[i] - 1;
                maxArea = max(maxArea, bottom * left[i][j]);
            }
            
        }
        return maxArea;

    }
};

int main(){
    Solution * solu = new Solution();
    vector<vector<char>> matrix;
    vector<char> row1{'1','0','1','0','0'};
    matrix.push_back(row1);
    matrix.push_back(vector<char>{'1','0','1','1','1'});
    matrix.push_back(vector<char>{'1','1','1','1','1'});
    matrix.push_back(vector<char>{'1','0','0','1','0'});
    int res = solu->maximalRectangle(matrix);
    cout << res << endl;

}