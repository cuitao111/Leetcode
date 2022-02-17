#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;

/*
按每一列拆分
向左右扩展，直到找到小于该位置的柱子，即为该位置的最大矩形

*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int sizeOfHeight = heights.size();
        vector<int> lbound(sizeOfHeight);
        vector<int> rbound(sizeOfHeight);

        stack<int> mono_stack;

        
        for(int i = 0; i < sizeOfHeight; i++){
            while(!mono_stack.empty() && 
            heights[mono_stack.top()] >= heights[i]){
                mono_stack.pop();
            }
            if(mono_stack.empty()){
                lbound[i] = -1;
            }else{
                lbound[i] = mono_stack.top();
            }
            mono_stack.push(i);
        }

        while(!mono_stack.empty()){
            mono_stack.pop();
        }


        for(int i = sizeOfHeight - 1; i >= 0; i--){
            while(!mono_stack.empty() && 
            heights[mono_stack.top()] >= heights[i]){
                mono_stack.pop();
            }
            if(mono_stack.empty()){
                rbound[i] = sizeOfHeight;
            }else{
                rbound[i] = mono_stack.top();
            }
            mono_stack.push(i);
        }

        int maxArea = 0;

        for(int i = 0; i < sizeOfHeight; i++){
            int bottom = rbound[i] - lbound[i] - 1;
            maxArea = max(maxArea, heights[i] * bottom);
        }
        return maxArea;
    }
};


int main(){
    Solution * solu = new Solution();
    vector<int> heights{6,7,5,2,4,5,9,3};
    int res = solu->largestRectangleArea(heights);
    cout << res << endl;
}