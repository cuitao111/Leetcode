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

/*
二叉搜索树构建

升序排列为二叉搜索树的中序遍历
*/

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int sizeOfNums = nums.size();

        if(sizeOfNums == 0){
            return nullptr;
        }
        return buildBinary(nums, 0, sizeOfNums - 1);

    }

    TreeNode * buildBinary(vector<int>& nums, int left, int right){
        if(left == right){
            // 如果只剩一个值来构建子树
            return new TreeNode(nums[left]);
        }
        if(left + 1 == right){
            // 两个点形成半个树
            TreeNode * lnode = new TreeNode(nums[left]);
            TreeNode * mnode = new TreeNode(nums[right]);
            mnode->left = lnode;
            return mnode;
        }
        // 保证每次均分,每次找left right中点
        int mid = (left + right) / 2;
        TreeNode * node = new TreeNode(nums[mid]);

        node->left = buildBinary(nums, left, mid - 1);
        node->right = buildBinary(nums, mid + 1, right);

        return node;
    }
};

int main(){
    Solution * solu = new Solution();
    vector<int> nums{-10,-3,0,5,9};
    TreeNode * res = solu->sortedArrayToBST(nums);
    queue<TreeNode *> q;
    q.push(res);
    while (!q.empty())
    {
        TreeNode * node = q.front();
        q.pop();
        if(node != nullptr){
            cout << node->val << endl;
        }else{
            cout << "null" << endl;
            continue;
        }
        
        if(!(node->left == nullptr && node->right == nullptr)){
            q.push(node->left);
            q.push(node->right);
        }

    }
    
    


}