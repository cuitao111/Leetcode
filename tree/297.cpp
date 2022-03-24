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
 s = "123.257";
    //string --> int;
    cout << stoi(s) << endl;
    //string --> int
    cout << stol(s) << endl;
    //string --> float
    cout << stof(s) << endl;
    //string --> doubel
    cout << stod(s) << endl;
*/

class Codec {
public:
    void reserialize(TreeNode * root, string & s){
        // 当左右子树全为空时
        if(root == nullptr){
            s += "None";
        }else{
            s += to_string(root->val) + ",";
            reserialize(root->left, s);
            reserialize(root->right, s);
        }

        
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // 将树的前序遍历输入到ret中
        string ret;
        reserialize(root, ret);
        return ret;
    }

    TreeNode * redeserialize(list<string>& dataArray){
        if(dataArray.front() == "None,"){
            dataArray.erase(dataArray.begin());
            return nullptr;
        }
        TreeNode * node = new TreeNode(stoi(dataArray.front()));
        dataArray.erase(dataArray.begin());
        node->left = redeserialize(dataArray);
        node->right = redeserialize(dataArray);
        return node;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // 先将string拆分为vector<string>
        list<string> dataArray;
        string str;
        for(auto& ch : data){
            // 以，作为分割方法
            if(ch == ','){
                dataArray.push_back(str);
                // 清空存下一个节点值
                str.clear();
            }else{
                str.push_back(ch);
            }
        }
        if (!str.empty()) {
            dataArray.push_back(str);
            str.clear();
        }
        TreeNode * root  = redeserialize(dataArray);
        return root;

    }
};

