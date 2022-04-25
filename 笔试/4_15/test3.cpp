#include <iostream>
#include <vector>

using namespace std;
// 上右左下
int driect[4][2] = {{1, 0}, {0, 1}, {-1,0}, {0, -1}};

int inRange(int x, int y, int m, int n){
    return x >= 0&& x < m && y >=0 && y < n;
}
int dfs(vector<vector<int>> & matrix, vector<vector<bool>> & vis, int i, int j, 
int score){
    int m = matrix.size();
    int n = matrix[0].size();
    if(i == m -1 && j == n -1){
        return score;
    }
    int res = -1;
    int end_flag = true;
    //重置分数
    for(int k = 0; k < 4;k++){
        int x = i + driect[k][0];
        int y = j + driect[k][1];
        int s = score;
        if(!inRange(x, y, m, n)){
            x = (x+m) % m;
            y =  (y + n) % n;
            s = 0;
        }
        // int x = (i + driect[k][0] + m) % m;
        // int y = (j + driect[k][1] + n) % n;
        if(!vis[x][y]){
            end_flag = false;
            vis[x][y] = true;
            s += matrix[x][y];
            int c_socre = dfs(matrix, vis,  x, y, s);
            res = max(res, c_socre);
            vis[x][y] = false;
        }
    }
    //四个方向不能走
    if(end_flag){
        return 0;
    }
    return res;
    
}


int getmaxscore(vector<vector<int>> & matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    vis[0][0] = true;
    return dfs(matrix, vis,  0, 0, matrix[0][0]);
}







int main(){

    int m, n;
    cin >> n >> m;
    vector<vector<int>> scores(m, vector<int>(n,0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> scores[i][j];
        }
    }
    cout << getmaxscore(scores);
    cout << "1" << endl;

}