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

/*
https://www.bilibili.com/video/BV1GE411G7Kq/?spm_id_from=autoNext
https://www.bilibili.com/video/BV1Q7411e7bM?spm_id_from=333.337.search-card.all.click
*/


class Solution {
public:
    void dfs(vector<vector<int>>& adj, int i, int times, \
    vector<int>& dfn, vector<int>& low, vector<int>& fa, vector<vector<int>>& res){
        int n  = adj.size();
        // 首先更新时间戳
        dfn[i] = low[i] = times++;
        int children = 0;
        // 从邻接表中搜索桥
        for(auto & j : adj[i]){
            if(fa[i] == j){
                continue;
            }
            // ij相连， j未访问过，j作为i的子节点
            if(dfn[j] == 0){
                children++;
                fa[j] = i;
                dfs(adj, j, times, dfn, low, fa, res);
                // 判断ij边是否为桥
                // dfn时间戳越靠小越靠上
                // j回溯不到i
                if(low[j] > dfn[i]){
                    res.push_back({i, j});
                }
                // 更新x的low
                low[i] = min(low[i], low[j]);
            }else{
                /*
                // j之前已经访问过，是i的祖先节点，更新low【i
                // low【u】的定义是从u和以u为root的subtree通过一条非树边能到达的最早的dfn，如果那里用low的话不能保证满足定义。
                // 如果使用low[j],需要借助j点过度到dfn[j]
                // 不是真正意义上的 *一条* 非树边
                */
                //如果j不是i的父节点 而是祖先节点， 更新
                    low[i] = min(low[i], dfn[j]);
            }
            
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>  res;
        if(n == 0){
            return res;
        }
        // 构建邻接表
        vector<vector<int>> adj;
        adj.resize(n);
        for(auto & edge : connections){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> dfn(n, 0), low(n, 0 ), fa(n, -1);
        // 定义时间戳
        int times = 1;
        for(int i = 0; i < n; i++){
            if(dfn[i] == 0){
                // 未访问过dfs为0
                dfs(adj, i, times, dfn, low, fa, res);
            }
            
        }
        return res;

    }   
};

int main(){
    Solution * solu = new Solution();
    vector<vector<int>> connections;
    connections.push_back({0,1});
    connections.push_back({1,2});
    connections.push_back({2,0});
    connections.push_back({1,3});
    vector<vector<int>> res = solu->criticalConnections(4,connections);

}