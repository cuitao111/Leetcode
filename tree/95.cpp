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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
n个值组成的列表
有n中不同的根节点选择方式

选择不同位置作为根节点，将左右两侧的可能结果用vector存储
之后组合压入vector 这样就又得到结果组合 用于上一层的调用

不需要使用nums，后面做到时优化

*/

class Solution {
public:
    vector<TreeNode *> generateMyTrees(vector<int> nums, 
    int left, int right){
        vector<TreeNode *> res;
        // 使用nums[left] 和 nums[right]之间的数构建树
        if(left == right){
            res.push_back(new TreeNode(nums[left]));
            // 只有一种构建方式
            return res;
        }
        if(left > right){
            res.push_back(nullptr);
            return res;
        }
        // 当right >= left + 1,至少有两个节点时
        // 从left-right依次作为根节点
        // 会产生不同的树，迭代过程中不断向tress中添加
        // 何时添加？左右两边同时构建，不好判断
        for(int i = left; i <= right; i++){
            // 第i个位置为根节点
            
            // left～i - 1为左子树
            vector<TreeNode *> ltrees = generateMyTrees(nums, left, i - 1);
            vector<TreeNode *> rtrees = generateMyTrees(nums, i + 1, right);
            // ltrees中包含了左半侧所有子树的情况,同理rtrees
            // 将ltrees和rtrees组合得到结果压入
            for(int j = 0; j < ltrees.size(); j++){
                for(int k = 0; k < rtrees.size(); k++){
                    TreeNode * root = new TreeNode(nums[i]);
                    // 这两句保证了二茶搜索树，数组左侧永远小于根节点
                    root->left = ltrees[j];
                    root->right = rtrees[k];
                    res.push_back(root);
                }
            }

        }
        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode *> trees;
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            nums[i] = i + 1;
        }

        return generateMyTrees(nums, 0 , n - 1);

    }
};


int main(){
    Solution * solu = new Solution();
    int n = 3;
    vector<TreeNode *>  trees = solu->generateTrees(n);
}