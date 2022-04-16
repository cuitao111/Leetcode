#include <iostream>
#include <vector>

using namespace std;
/*
能到达需要满足两个条件
数位和大于k
需要和（0，0）在同一块陆地上 
回溯 ，需要建数组，遍历过需要置1，


需要提前遍历一遍 将不可达的位置置为1?
递归中首次遇到不可达的地方置1

有没有可能 上次dfs导致有些位置无法遍历到

向右和下两个方向遍历即可
*/



class Solution {
    int direction[3] ={ 0, 1 ,0};
public:
    int movingCount(int m, int n, int k) {
        vector<vector<int>> vis(m, vector<int>(n, 0));
        if(k < 0){
            return 0;
        }
        vis[0][0] = 1;
        return dfs(vis, 0, 0, 1, k);
    }

    int dfs(vector<vector<int>> & vis, int i, int j, int dis, int k_v){
        int m = vis.size();
        int n = vis[0].size();
        // 判断上下左右的位置是否可达
        for(int k = 0; k < 2; ++k){
            int x = i + direction[k];
            int y = j + direction[k + 1];
            if(inRange(x,y,m,n) && !vis[x][y]){
                vis[x][y] = 1;
                if(!lessThanK(x,y,k_v)){
                    // 不进行递归
                    continue;;
                }
                // 递归
                dis = dfs(vis, x, y, dis + 1, k_v);
                
            }
        }
        // 如果四周都不可达dis不变
        return dis;

    }

    bool inRange(int i ,int j, int m, int n){
        return i>=0&&j>=0&&i<m&&j<n;
    }


    // 满足可以进入
    bool lessThanK(int i, int j, int k){
        int sum = 0;
        while (i != 0)
        {
            sum += i % 10;
            i /= 10;
        }
        while (j != 0)
        {
            sum += j % 10;
            j /= 10;
        }
        return sum <= k;
    }
};

int main(){
    Solution *solu = new Solution();
    // cout << solu->movingCount(2,3,17);
    bool a = false;
    cout << sizeof(bool);
    cin.get();
}