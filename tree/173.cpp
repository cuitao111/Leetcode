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

class BSTIterator {
    TreeNode * cur = new TreeNode(-1);
    stack<TreeNode *> stk;
public:
    BSTIterator(TreeNode* root) {
        cur = root;
    }
    
    int next() {
        // 若上一次的cur为null,top位置为上一节点的父节点
        while(cur != nullptr){
            stk.push(cur);
            cur = cur->left;
        }
        cur = stk.top();
        stk.pop();
        int res = cur->val;
        cur = cur->right;
        return res;
    }
    
    bool hasNext() {
        if(cur != nullptr || !stk.empty()){
            return true;
        }
    }
};