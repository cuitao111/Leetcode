#include <iostream>
#include <vector>

using namespace std;

/*
移动速度相同
RR 为 0 RRS 为2
从左到右判断向左撞的次数，从右到左判断向右撞的次数
第一次判断完，更改string后是否影响第二次
*/

class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.length();
        int lcrash = 0, rcrash = 0;
        for(int i = 1; i < n; i++){
            if(directions[i] == 'L'){
                // 如果i位置的车向左撞
                if(directions[i - 1] != 'L'){
                    lcrash++;
                    directions[i] = 'S';
                }
            }
        }

        for(int i = n - 2; i >= 0; i--){
            if(directions[i] == 'R'){
                if(directions[i + 1] == 'S'){
                    // 经过第一次循环之后R的右边不可能存在L
                    rcrash++;
                    directions[i] = 'S';
                }
            }
        }
        return lcrash + rcrash;
    }
};

int main(){
    Solution * solu = new Solution();
    string s = "RLRSLL";
    string s1 = "LLRR";
    cout << solu->countCollisions(s1) << endl;

}