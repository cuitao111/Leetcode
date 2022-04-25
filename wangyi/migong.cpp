#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

class Solution{
public:
    int getPath(vector<vector<char>> & maze, int m, int n){
        int start_x, start_y;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(maze[i][j] == '*'){
                    start_x = i;
                    start_y = j;
                    break;
                }
            }
        }
        // 从start_x 和 start_y出发需要的步数
        return backstrack(maze, start_x , start_y);
    }

    int backstrack(vector<vector<char>> & maze, int x, int y){
        // 找最近的宝箱
        int m = maze.size();
        int n = maze[0].size();
        int distance = 0;
        int target_x, target_y;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(maze[i][j] >= '0' && maze[i][j] <= '9'){
                    distance = max(distance, abs(x - i) + abs(y - j));
                    target_x = i;
                    target_y = j;
                }
            }
        }
        // 到targetx y的路径
        // *的位置需要更新？
        // 上
        if(x > 0 && maze[x - 1][y] != '#'){
            if(backstrack(maze, x - 1, y, target_x, target_y) >)
        }
    }
};