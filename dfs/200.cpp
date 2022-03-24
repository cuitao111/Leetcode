#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <memory>
#include <queue>
#include <list>
#include <numeric>

using namespace std;

class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid,vector<vector<bool>>& vis){
        int m = grid.size();
        int n = grid[0].size();
        // 什么时候返回0 什么时候返回1
        vis[i][j] = true;
        if(grid[i][j] == '1'){
            if(i > 0 && !vis[i - 1][j]){
                dfs(i - 1, j, grid, vis);
            }
            if(i < m - 1 && !vis[i + 1][j]){
                dfs(i + 1, j, grid, vis);
            }
            if(j > 0 && !vis[i][j - 1]){
                dfs(i, j - 1, grid, vis);
            }
            if(j < n - 1 && !vis[i][j + 1]){
                dfs(i, j + 1, grid, vis);
            }
        }
        

    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m == 0){
            return 0;
        }
        int n = grid[0].size();
        int sum = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0;j < n; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(i, j, grid, vis);
                    sum++;
                }
            }
        }
        return sum;
    }
};


int main(){
    Solution * solu = new Solution();
    vector<vector<char>> grid;
    grid.push_back({'1','1','1','1','0'});
    grid.push_back({'1','1','0','1','0'});
    grid.push_back({'1','1','0','0','0'});
    grid.push_back({'0','0','0','0','0'});
    int res = solu->numIslands(grid);
}