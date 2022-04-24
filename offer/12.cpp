#include <iostream>
#include <vector>

using namespace std;

/*
使用vis记录是否访问过
如果找到中途断掉，需要递归重设为0吗
还是直接传值，不传引用

backstrack(&s)
能传引用就传引用 60% 和90%
*/

class Solution{
    
public:
    int ref[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    bool ans = false;
    bool exist(vector<vector<char>> & board, string word){
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    // cout << board[i][j] << "->";
                    if(word.size() == 1){
                        return true;
                    }
                    int temp=board[i][j];
                    board[i][j]=0;
                    ans |= backstrack(board,i,j,1, word);
                    if(ans) return true;
                    board[i][j]=temp;
                    // cout << endl;
                }
            }
        }
        return ans;
    }

    bool backstrack(vector<vector<char>> & board,int i, int j, int idx, string s){
        int m = board.size();
        int n = board[0].size();
        // 使用direction获取四个方向
        // int x,y;
        for(int k = 0; k < 4; ++k){
            int x = i + ref[k][0];
            int y = j + ref[k][1];
            // 判断x，y位置是否越界
            if(inRange(x, y, m, n) && board[x][y] == s[idx]){
                // cout << board[x][y] << "->";
                if(idx == s.length()){
                    return true;
                }
                int temp=board[x][y];
                board[x][y]=0;
                ans |= backstrack(board,x,y,idx + 1, s);
                if(ans) return true;
                board[x][y]=temp;
            }
        }
        // cout << endl;
        return ans;
    }

    inline bool inRange(int x, int y, int m, int n)
    {
        return x>=0&&x < m&&y >= 0&&y < n;
    }
};


int main(){

    Solution * solu = new Solution();
    vector<vector<char>> board;
    board.push_back({'a','b','c','e'});
    board.push_back({'s','f','c','s'});
    board.push_back({'a','d','e','e'});


    string s= "abcced";

    bool res = solu->exist(board, s);
    cout << res<< endl;
    cin.get();

    return 0;
}