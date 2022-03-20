#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
遇到边界返回
每次有右侧和下侧两个路径选择，递归调用
超出时间限制

以3，7为例
共有两次向下的机会
当第一次在i处向下，第二次就有7-i个位置可以下降，七条路径

以4，7为例
三次下降
第一次位置为i 第二次 可以下降的位置为[i, 7]
分别对应的路径数为[7-i, 7 - i - 1, .. 1]
最终结果为sum(7-0) + sum(6) + sum(1)

f(i,j)=f(i−1,j)+f(i,j−1)

*/



class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> f(m, vector<int>(n));
        for(int i = 0; i < m; i++){
            // 左边界
            f[i][0] = 1;
        }
        for(int i = 0; i < n; i++){
            // 上边界
            f[0][i] = 1;
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }
        return f[m - 1][n - 1];

    }
};

int main(){
    Solution * solu = new Solution();
    int m = 51, n = 9;
    int res = solu->uniquePaths(m , n );
    cout << res << endl;
}