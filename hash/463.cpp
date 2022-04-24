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
    int getPerimeter(vector<vector<int>>& grid, int i, int j,
    vector<vector<bool>> & vis){
        int res = 0;
        if(vis[i][j] == true){
            return 0;
        }
        vis[i][j] = true;
        // 上
        if(i == 0 || grid[i - 1][j] == 0)
        {
            res++;
        }
        // 左
        if(j == 0 || grid[i][j - 1] == 0){res++;}
        // 右
        if(j == grid[0].size() - 1 || grid[i][j +1] == 0){res++;}
        // 下
        if(j == grid.size() || grid[i + 1][j] == 0){res++;}

    }

    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.size() == 0){
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>& vis{m, vector<bool>(n, false)};
        int sum = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; i < grid[0].size(); j++){
                if(vis[i][j]){
                    continue;
                }
                if(grid[i][j] == 1){
                    return getPerimeter(grid, i, j, vis);
                }
            }
        }
        return 0;

    }
};