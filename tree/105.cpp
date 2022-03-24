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
// 构造哈希映射，帮助我们快速定位根节点
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }
// 使用find和distance也可
auto it = find(inorder.begin(), inorder.end(), cur);
        int inindex = distance(inorder.begin(), it);

*/

class Solution {
public:

    TreeNode * buildMyTree(vector<int>& preorder, vector<int>& inorder,
     int pleft, int pright, int ileft, int iright){
        //  传入的前中序只有一个元素
        if(pleft == pright){
            return new TreeNode(preorder[pleft]);
        }
        // 如果传入的preorder下标范围内不存在元素
        if(pleft > pright){
            return nullptr;
        }
        // 在中序遍历中找到先序第一个即可拆分左右子树
        int cur = preorder[pleft];
        auto it = find(inorder.begin(), inorder.end(), cur);
        int inindex = distance(inorder.begin(), it);
        TreeNode * node = new TreeNode(cur);
        // 中序遍历左侧长度 inindex - ileft
        // 右侧长度 iright - inindex
        node->left = buildMyTree(preorder, inorder, pleft + 1, 
        pleft + inindex - ileft, ileft, inindex - 1);
        node->right = buildMyTree(preorder, inorder, pleft + inindex - ileft + 1,
        pright, inindex + 1, iright);
        return node;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return buildMyTree(preorder, inorder, 0, n - 1, 0, n -1);
    }
};

int main(){
    Solution * solu = new Solution();
    vector<int> preorder{1,2,3};
    vector<int> inorder{3,2,1};
    TreeNode * res = solu->buildTree(preorder, inorder);
    cout << res->val << endl;
}