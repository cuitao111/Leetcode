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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
preorder:3939 inorder:9393 对应的树有两种

知识点：vector寻找下标 vector片段截取
遍历inorder时间复杂度高
使用hash表来存储位置
*/


class Solution {
public:
    unordered_map<int, int> mp;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int sizeOfTree = preorder.size();

        if(sizeOfTree == 0){
            return nullptr;
        }

        if(sizeOfTree == 1){
            return new TreeNode(preorder[0]);
        }
        for(int i = 0; i <  sizeOfTree; i++){
            mp[inorder[i]] = i;
        }
        // 参数：前序中序 前序范围， 中序范围
        return buildMyTree(preorder, inorder, 0 , sizeOfTree - 1, 0 , sizeOfTree -1);

    }

    TreeNode * buildMyTree(vector<int>& preorder, vector<int>& inorder,
     int pbegin, int pend, int ibegin, int iend){
        //  将当前preorder的第一个节点取出构建根节点
        TreeNode * root = new TreeNode(preorder[pbegin]);
        // 从hash表中找出对应位置
        int inindex = mp[preorder[pbegin]];
        // 左侧树的总长度
        int lenOfLeft = inindex - ibegin;
        int lenOfRight = iend -inindex;
        // 当左节点为null时 lenleft为0 右侧同理
        if(lenOfLeft != 0){
            root->left = buildMyTree(preorder, inorder,pbegin + 1, 
            pbegin + lenOfLeft, ibegin, inindex - 1);
        }

        if(lenOfRight != 0){
            root->right = buildMyTree(preorder, inorder, pbegin + lenOfLeft + 1,
            pend, inindex + 1, iend);
        }
        return root;
     }
};


int main(){
    Solution * solu = new Solution();
    vector<int> preorder{3,9,20,15,7};
    vector<int> inroder{9,3,15,20,7};
    TreeNode * res = solu->buildTree(preorder, inroder);
    queue<TreeNode *> q;
    q.push(res);
    while (!q.empty())
    {
        TreeNode * front = q.front();
        if(front != nullptr){
            q.push(front->left);
            q.push(front->right);
            std::cout << front->val << endl;
        }
        q.pop();
    }
    std::cout << 1 << endl;

}