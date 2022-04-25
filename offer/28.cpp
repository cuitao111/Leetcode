#include <iostream>
#include <queue>
using namespace std;

//  * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*左右广度遍历的过程的路径应该一致*/

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode *> leftbfs;
        queue<TreeNode *> rightbfs;
        leftbfs.push(root);
        rightbfs.push(root);
        while(!leftbfs.empty() || !rightbfs.empty()){
            if(leftbfs.empty() || rightbfs.empty()){
                return false;
            }
            TreeNode * left = leftbfs.front();
            TreeNode * right = rightbfs.front();
            if(left != nullptr && right != nullptr && left->val == right->val){
                leftbfs.push(left->left);
                leftbfs.push(left->right);
                leftbfs.pop();
                rightbfs.push(right->right);
                rightbfs.push(right->left);
                rightbfs.pop();
            }else if(left == nullptr && right == nullptr){
                leftbfs.pop();
                rightbfs.pop();
                continue;
            }else{
                return false;
            }
        }
        return true;
    }
};