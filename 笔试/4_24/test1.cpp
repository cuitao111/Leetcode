#include <iostream>
#include <vector>
#include <string>
using namespace std;

int getmin(string & s, int n){
    int res = -1;
    vector<int> atk(n + 1);
    vector<int> dfs(n + 1);
    atk[0] = 0;
    dfs[n] = 0;
    for(int i = 1; i <= n; i++){
        atk[i] = s[i - 1] == '0' ? atk[i - 1] + i : atk[i - 1];
    }
    for(int i = n - 1; i >=0 ; i--){
        dfs[i] = s[i] == '1' ? dfs[i + 1] + i + 1 : dfs[i+1];
    }
    res = abs(atk[0] - dfs[0]);
    for(int i = 1; i <=n; i++){
        res = min(res, abs(atk[i] - dfs[i]));
    }
    return res;
}


int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    cout  << getmin(s, n);
}