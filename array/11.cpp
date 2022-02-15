#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
影响装水体积的因素有两个，底和高
h也就是数组的val的值越大越好
b间隔越开越好
在选取高度最高的同时尽量保证少缩减宽度
如果遇到缩减一步体积增大，且内部高要大于之前的高，则必然要舍弃之前的边，向内部压缩一位
如果内部高度要低，内侧高度对应的体积必然要小于外侧对应的
因此每次只需要比较内部高于容器边高度对应的体积是否大于原先体积
*/

/*
从最高点向左右两侧找，确定号lbound和rbound
最大容积必然包括最高点，如果最高点在最大容积两侧则会产生矛盾
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int sizeOfHeight = height.size();
        // 定义左右两个指针
        int left = 0, right = sizeOfHeight - 1;
        // 定义最大容积
        int maxVolume  = 0;
        // 循环条件 left < right 若为==则构成不了容器
        while(left < right){
            // 两侧的高度
            int lheight = height[left];
            int rheight = height[right];
            // 底
            int bottom = right - left;
            // 判断容积是否变大 
            maxVolume = max(maxVolume, bottom * min(lheight, rheight));
            // 找两侧高度较小的进行向内侧移动
            // 若移动高的，容器高度不会变大，而底会变小
            // 体积也只会减小
            if(lheight < rheight){
                left++;
            }else{
                right--;
            }
        }
        return maxVolume;
    }
};

int main(){
    Solution * solu = new Solution();
    vector<int> height{2,3,4,5,18,17,6};
    int res = solu->maxArea(height);
    cout << res << endl;
}