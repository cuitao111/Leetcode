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
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        // 递归返回,如果遇到叶子节点
        if(root->left == nullptr && root->right == nullptr){
            return 1;
        }
        // 获取左右子树的深度
        int ldepth = maxDepth(root->left);
        int rdepth = maxDepth(root->right);

        return max(ldepth, rdepth) + 1;
    }

};

int main(){
    Solution * solu = new Solution();
    vector<int> nums{3,9,20,-1,-1,15,7};
    queue<TreeNode *> q;
    TreeNode * root = new TreeNode(nums[0]);
    q.push(root);
    int index = 1;
    while (!q.empty() && index < nums.size())
    {
        TreeNode * node = q.front();
        // 建立两个节点连接
        if(nums[index] != -1){
            TreeNode * lnode = new TreeNode(nums[index]);
            node->left = lnode;
            q.push(lnode);
        
        }

        if(nums[index + 1]){
            TreeNode * rnode = new TreeNode(nums[index + 1]);
            node->right = rnode;
            q.push(rnode);
        }
        
        q.pop();
        
        index += 2;
    }
    

    int res = solu->maxDepth(root);
    cout << res << endl;

}