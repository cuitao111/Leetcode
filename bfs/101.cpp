#include <iostream>
#include <vector>
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
广度优先搜索

*/

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        
        queue<TreeNode *> q;
        q.emplace(root->left);
        q.emplace(root->right);
        while (!q.empty())
        {
            TreeNode * node1 = q.front();
            q.pop();
            TreeNode * node2 = q.front();
            q.pop();
            if((node1 != nullptr && node2 == nullptr) || 
            (node1 == nullptr && node2 != nullptr)){
                return false;
            }
            if(node1 == nullptr && node2 == nullptr){
                continue;
            }
            if(node1->val != node2->val){
                return false;
            }
            q.push(node1->left);
            q.push(node2->right);
            q.push(node1->right);
            q.push(node2->left);
        }
        return true;
    }
};


int main(){
    Solution * solu = new Solution();
    vector<int> nums{1,2,2,3,4,4,3};
    TreeNode * dummyHead = new TreeNode(nums[0]);
    queue<TreeNode *> q;
    q.emplace(dummyHead);
    for(int i = 1; i < nums.size(); i+= 2){
        TreeNode * node = q.front();
        q.pop();
        TreeNode * left = new TreeNode(nums[i]);
        TreeNode * right = new TreeNode(nums[i + 1]);
        node->left = left;
        node->right = right;
        q.emplace(left);
        q.emplace(right);
    }
    bool res = solu->isSymmetric(dummyHead);
}