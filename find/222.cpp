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

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        // 确定level层
        TreeNode * node = root;
        int level = 0;
        while (node->left != nullptr)
        {
            level++;
            node = node->left;
        }
        int left = 1 << level, right = (1 << (level + 1)) - 1;

        // 1000在最左侧 1111在最右侧 0左 1右
        // 最后一层的坐标为1 << level ~ 1 << (level + 1) - 1
        // 最后退出时应该定位到最后一个存在的节点，
        // 当只有一个节点也能判断正确
        while(left < right){
            
            // 向上取整
            int mid = (left + right + 1) / 2;
            if(isexists(root, level, mid)){
                // right
                left = mid;
            }else{
                right = mid - 1;
            }
        }
        return right;
    }
    
    bool isexists(TreeNode * root, int level, int k ){
        // 根据n的后k - 1位来寻找节点是否存在
        int bits = 1 << (level - 1);
        TreeNode * node = root;
        while (node != nullptr && bits > 0)
        {
            if(k & bits){
                // 1
                node = node->right;
            }else{
                node = node->left;
            }
            bits = bits >> 1;
        }
        return node != nullptr;
        
    }
};

int main(){
    Solution * solu = new Solution();
    vector<int> nums{1,2,3,4,5,6};
    TreeNode * dummyRoot = new TreeNode(nums[0]);
    // queue<TreeNode *> q;
    // q.push(dummyRoot);
    // int i = 1;
    // while (!q.empty() && i < nums.size())
    // {
    //     TreeNode * root = q.front();
    //     q.pop();
    //     TreeNode * left = new TreeNode(nums[i]);
    //     root->left = left;
    //     q.push(left);
    //     if(i + 1 < nums.size()){
    //         TreeNode * right = new TreeNode(nums[i + 1]);
    //         root->right = right;
    //         q.push(right);
    //     }
    //     i += 2;
    // }
    int res = solu->countNodes(dummyRoot);
    cout << res << endl;
    
}