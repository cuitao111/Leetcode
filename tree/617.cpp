#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <memory>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr && root2 == nullptr){
            return nullptr;
        }
        // 只要有一个节点不为空，就需要将子结点作为参数传入函数调用
        
        // 前面已经有两个节点都为空的情况判断
        if(root1 == nullptr){
            // 不为 null 的节点将直接作为新二叉树的节点
            return root2;
        }

        if(root2 == nullptr){
            return root1;
        }
        

        TreeNode * node = new TreeNode(root1->val + root2->val);

        node->left = mergeTrees(root1->left, root2->left);
        node->right = mergeTrees(root1->right, root2->right);
        return node;
        
    }
};