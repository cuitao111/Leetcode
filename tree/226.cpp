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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr){
            return root;
        }
        // 叶子节点也直接返回
        if(root->left == nullptr && root->right == nullptr){
            return root;
        }
        // 无法使用temp交换，总会调用函数赋值参数
        // 建立两个新节点，占用空间
        TreeNode * left = invertTree(root->left);
        TreeNode * right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};

int main(){

}