#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 中序遍历 同时计数，计算到k结束

class Solution {
public:
    int cur_order;
    int k_num;
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr){
            return -1;
        }
        cur_order = k;
        dfs(root);
        return k_num;
    }

    void dfs(TreeNode * root){
        if(root == nullptr || cur_order==0){
            return;
        }
        dfs(root->left);
        cur_order--;
        if(cur_order == 0){
            k_num = root->val;
        }
        dfs(root->right);
    }
};