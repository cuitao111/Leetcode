#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
思路一：
暴力解法，每次只看一列
从左右两侧找出最高的值，取两边较小的值减去该值
就是这一列存储的雨水

*/


class Solution {
public:
    int trap(vector<int>& height) {
        // 设置变量存储雨水
        int totalRain = 0;
        // 列表长度
        int sizeOfHeight = height.size();
        // 空间换时间
        vector<int> lmax(sizeOfHeight);
        vector<int> rmax(sizeOfHeight);
        // 从左到右侧填充lmax
        lmax[0] = height[0];
        for(int i = 1; i < sizeOfHeight; i++){
            lmax[i] =  max(lmax[i - 1], height[i]);
        }
        // 从右侧到左填充
        rmax[sizeOfHeight - 1] = height[sizeOfHeight - 1];
        for(int i = sizeOfHeight - 2; i >= 0; i--){
            rmax[i] = max(height[i], rmax[i + 1]);
        }
        for(int i = 1; i < sizeOfHeight - 1 ; i++){
            totalRain = min(lmax[i], rmax[i]) - height[i];
        }
        return totalRain;
    }
};

int main(){
    Solution * solu = new Solution();
    vector<int> height{4, 2, 3};
    int res = solu->trap(height);
    cout << res << endl;
}