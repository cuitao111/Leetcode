#include <iostream>
#include <vector>

using namespace std;


int dfs(vector<string> & maze, vector<vector<bool>> &vis,
int start_x, int start_y, int fin_x, int fin_y, int dis){
    // 从start出发向上下左右找.
    int n = maze.size();
    int m = maze[0].size();
    int distance = -1;
    if(start_x == fin_x && start_y == fin_y){
        return dis;
    }
    vis[start_x][start_y] = true;
    if(start_x > 0 && maze[start_x - 1][start_y] != '#' && !vis[start_x - 1][start_y]){
        // 向上走
        int up_dis = dfs(maze,vis, start_x - 1, start_y, fin_x, fin_y, dis + 1);
        distance = distance == -1 ? up_dis : min(up_dis, distance);
    }
    // 下
    if(start_x < n -1 && maze[start_x + 1][start_y] != '#' && !vis[start_x + 1][start_y]){
        int up_dis = dfs(maze,vis, start_x + 1, start_y, fin_x, fin_y, dis + 1);
        distance = distance == -1 ? up_dis : min(up_dis, distance);
    }
    // 左侧
    if(start_y > 0 && maze[start_x][start_y-1] != '#' && !vis[start_x][start_y-1]){
        int up_dis = dfs(maze,vis, start_x, start_y - 1, fin_x, fin_y, dis + 1);
        distance = distance == -1 ? up_dis : min(up_dis, distance);
    }

    if(start_y < m -1 && maze[start_x][start_y+1] != '#' && !vis[start_x][start_y+1]){
        int up_dis = dfs(maze,vis, start_x, start_y+1, fin_x, fin_y, dis + 1);
        distance = distance == -1 ? up_dis : min(up_dis, distance);
    }

    return distance;
}

int backstrack(vector<string> & maze, vector<vector<int>> & stone, int idx,
int start_x, int start_y, int t){
    int n = maze.size();
    int m = maze[0].size();
    int k = stone.size();
    if(idx == k){
        // 遍历完所有石头，返回
        return t;
    }
    int next_x, next_y;
    // 找出stone[idx]的上下左右
    // 可达就计算距离，取最小,之后从最小位置往下一个位置找
    int stone_x = stone[idx][0] - 1, stone_y = stone[idx][1] - 1;
    int distance = -1;
    

// 上面为.
    if(stone_x > 0 && maze[stone_x - 1][stone_y] != '#'){
        // 计算从start_x, start_y 到stone_x - 1, stone_y 距离
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int dis = dfs(maze,vis, start_x, start_y, stone_x - 1, stone_y, 0);
        if((distance == -1) || (distance > dis)){
            distance = dis;
            next_x = stone_x - 1;
            next_y = stone_y;
        }
    }

    if(stone_x < n - 1 && maze[stone_x + 1][stone_y] != '#'){
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int dis = dfs(maze,vis, start_x, start_y, stone_x + 1, stone_y, 0);
        if((distance == -1) || (distance > dis)){
            distance = dis;
            next_x = stone_x + 1;
            next_y = stone_y;
        }
    }

    if(stone_y > 0 && maze[stone_x][stone_y - 1] != '#'){
        // 计算从start_x, start_y 到stone_x - 1, stone_y 距离
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int dis = dfs(maze,vis, start_x, start_y, stone_x, stone_y - 1, 0);
        if((distance == -1) || (distance > dis)){
            distance = dis;
            next_x = stone_x;
            next_y = stone_y - 1;
        }
    }

    if(stone_y < m -1 && maze[stone_x][stone_y + 1] != '#'){
        // 计算从start_x, start_y 到stone_x - 1, stone_y 距离
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int dis = dfs(maze,vis, start_x, start_y, stone_x, stone_y + 1, 0);
        if((distance == -1) || (distance > dis)){
            distance = dis;
            next_x = stone_x;
            next_y = stone_y + 1;
        }
    }

    if(distance == -1){
        return -1;
    }
    return backstrack(maze, stone, idx + 1, next_x, next_y, t + distance);

}

int getMinDistance(vector<string> & maze, vector<vector<int>> & stone,
    int start_x, int start_y, int fin_x, int fin_y){
    int n = maze.size();
    int m = maze[0].size();
    int res;
    // 0:   目标为 stone[0]
    // start_x, start_y当前位置
    res = backstrack(maze, stone, 0, start_x, start_y, 0);
    cout << "distance:" << res << endl;
    return res;

}









int main(){

    int n, m, k;
    int start_x, start_y;
    int fin_x, fin_y;
    // cin >> n >> m >> k;
    vector<string> maze(n , "");
    vector<vector<int>> stone(k, vector<int>(2,0));
    maze.push_back("#....");
    maze.push_back("####.");
    maze.push_back("FS...");
    stone.push_back({1,1});
    stone.push_back({2,3});
    stone.push_back({2,2});
    start_x = 2;
    start_y = 1;
    fin_x = 2;
    fin_y = 0;


    /*
    for(int i = 0; i < n; i++){
        cin>> maze[i];
    }
    
    for(int i = 0; i < k; i++){
        cin >> stone[i][0] >> stone[i][1];
    }
    */
    

    int res = getMinDistance(maze, stone, start_x, start_y,fin_x, fin_y);
    cout << res <<endl;
    cin.get();

    return 0;
}