#include <iostream>
#include <vector>

using namespace std;

/*
b获得最高分 分配numArrows支箭
需要在越高位置超过A 如果A的数量过多也不是
如 7 8 9
A  0 0 8
B  1 1 0
比起把9支箭分配到 9 更好的选择是分配到 7 8

贪心： 每次从大到小 分配 比A 多一支的箭
然后考虑不分配给该位置的得分
f(nums, n - 1, anums + 1)
如果剩余的箭数小于位置i处a的箭，向左移位，
移动到左侧头部说明无论放在哪里都不影响得分


从左向右建立数组，表示分配numsArrows个值最大得分
寻找socre[i] 和score[i - 1]关系

*/

class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> res;
        int n  = aliceArrows.size();
        if(n == 0){
            return res;
        }
        res.resize(n, 0);
        if(numArrows == 0){
            return res;
        }
        // 将 numArrows分配到aliceArrows 0~n-1中,结果存在res
        for(int i = n - 1; i > 0; i--){
            if(numArrows == 0){
                break;
            }else if(aliceArrows[i] < numArrows){
                // 判断将 aliceArrows[i] + 1 支箭分配到0～i-1处得分是否大于i
                if(aliceArrows[i] == 0){
                    res[i] = 1;
                    numArrows--;
                    continue;
                }
                // 不分配给i的情况
                int ndisti = getScore(numArrows, aliceArrows, i - 1);
                // 分配给i
                int disti = getScore(numArrows - aliceArrows[i] - 1, aliceArrows, i - 1) + i;
                if(disti > ndisti){
                    res[i] = aliceArrows[i] + 1;
                    numArrows -= aliceArrows[i] + 1;
                }
            }
        }
        res[0] = numArrows;
        
        return res;
    }

    int getScore(int numArrows, vector<int>& aliceArrows, int n){
        if(n == 0 || numArrows == 0){
            // 分配到0处为0分
            return 0;
        }
        // 将n支箭分配到0~n
        int score = 0;
        for(int i = n; i >= 0; i--){
            // 判断是否可以在i处分配箭
            if(numArrows == 0){
                break;
            }else if(aliceArrows[i] < numArrows){
                // 判断将 aliceArrows[i] + 1 支箭分配到0～i-1处得分是否大于i
                if(aliceArrows[i] == 0){
                    score += i;;
                    numArrows--;
                    continue;
                }
                // 不分配给i的情况
                int ndisti = getScore(numArrows, aliceArrows, i - 1);
                // 分配给i
                int disti = getScore(numArrows - aliceArrows[i] - 1, aliceArrows, i - 1) + i;
                if(disti > ndisti){
                    // 得分+i
                    score += i;
                    numArrows -= aliceArrows[i] + 1;
                }
            }
        }
        return score;
    }
};

int main(){
    Solution * solu = new Solution();
    int numsArrows = 8;
    vector<int> aliceArrows{1,1,0,1,0,0,2,1,0,1,2,0};
    vector<int> aliceArrows1{0,0,1,0,0,0,0,0,0,0,0,2};
    vector<int> aliceArrows2{0,1,0,2,0,0,1,0,1,0,1,2};
    vector<int> res = solu->maximumBobPoints(numsArrows, aliceArrows2);
    cin.get();
}