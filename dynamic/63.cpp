#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid.at(0).size();
        vector <int> f(m);

        f[0] = (obstacleGrid[0][0] == 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    f[j] = 0;
                    continue;
                }
                if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0) {
                    f[j] += f[j - 1];
                }
            }
        }

        return f.back();
    }
};

// int main(){
//     Solution * solu = new Solution();
//     int m = 51, n = 9;
//     vector<vector<int>> map;
//     map.push_back({0,0,0,0,0,0,0,0});
//     map.push_back({0,0,0,0,0,0,0,0});
//     map.push_back({0,0,0,0,0,0,0,0});
//     map.push_back({0,0,0,1,0,0,0,0});
//     map.push_back({0,0,0,0,0,0,0,0});
//     map.push_back({0,0,0,0,0,0,0,0});
//     int res = solu->uniquePathsWithObstacles(map);
//     cout << res << endl;
//     cin.get();
// }

struct  Packet
{
    /* data */
    int var1;
    uint16_t var2;
};

// int main(){
//     unsigned char a[10] = {0xfe,0x45,0x30,0x01,0x00, 0x00,0xef, 0x10, 0x01};
//     const Packet * packet = (const Packet *)&a[2];
//     cout << packet->var1 <<"," <<packet->var2 <<endl;
//     cin.get();
//     return 0;
// }


// int main(){
//     vector<double> v;
//     v.reserve(5);
//     v[0] = 1;
//     v[1] = 2;
//     v.push_back(3);
//     cout << v.capacity() <<"," <<v.size() <<','<<v[0] <<',' <<v[1] << ',' << v[2]<<endl;
//     cin.get();
//     return 0;
// }

int main(){
    int var[] = {9,8,7,6,5,4,3,2,1,0};
    memcpy(&var[1] + 3, var, 5);
    for(int i = 0; i < 10; i ++){
        printf("%d", var[i]);
    }
    cin.get();
    return 0;
}