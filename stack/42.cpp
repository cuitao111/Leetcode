#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <memory>
#include <queue>
#include <list>

using namespace std;

/*
\textit{left}left 变成新的 \textit{top}top
先把底部填平，原先高变成底
*/

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int sumOfArea = 0;

        for(int i = 0; i < height.size(); i++){
            // 当遇到一个较高的height时，进入循环开始寻找储水区域
            while (!stk.empty() && height[i] > height[stk.top()])
            {
                // 底部高度对应的index
                int bindex = stk.top();
                stk.pop();
                // 判断是否还有元素，没有元素不呢构成容器
                if(stk.empty()){
                    break;
                }
                int lindex = stk.top();
                int h = min(height[i], height[lindex]) - height[bindex];
                sumOfArea += (i - lindex - 1) * h;
                // 之后原先的left变为top看是否能构成其他容器

            }

            stk.push(i);


        }

        return sumOfArea;
    }
};