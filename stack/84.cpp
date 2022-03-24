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
使用栈
遍历高度向左右两侧扩展
从左向右侧遍历， 确定左边界
如果出现递减关系，则左侧的比不可能为左边界，因此左边的可以直接出栈
所以当第i个位置入栈前后，栈里一定时递增关系
需要把高度大于i的值全部剔除
左边界：离i最近的 小于 i高度的位置

单调栈 + 优化
topi出栈时 对应处理的i为右边界
最后栈里还有一部分元素，他们的有边界如何确定
当最大矩形对应的h有很多下标时，左侧的不能找到正确的有边界，
但最右侧的一定可以

*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        stack<int> stk;
        int maxOfArea = 0;
        vector<int> lbound(size);
        vector<int> rbound(size);
        for(int i = 0; i < size; i++){
            // 确定左边界，向左找到第一个小于i高度的位置
            while(!stk.empty() && heights[stk.top()] > heights[i]){
                // 当高度大于height[i]时，弹出j，此时j为i的右边界
                int topi = stk.top();
                // 每个元素都要被push一遍，最后留在栈里的元素？
                stk.pop();
                rbound[topi] = i;
            }
            if(stk.empty()){
                lbound[i] = -1;
            }else{
                lbound[i] = stk.top();
            }
            stk.push(i);
        }
        // 循环最后一步一定是push(size - 1)
        // 栈内的元素还没确定有边界，他们是单调的一定能达到有边界
        while (!stk.empty())
        {
            rbound[stk.top()] = size;
            stk.pop();
        }
        for(int i = 0; i < size; i++){
            maxOfArea = max(maxOfArea, heights[i] * (rbound[i] - lbound[i] - 1));

        }
        return maxOfArea;
        
    }

};

int main(){
    Solution * solu = new Solution();
    vector<int> heights{2,1,5,6,2,3};
    int res = solu->largestRectangleArea(heights);
    cout << res << endl;
}