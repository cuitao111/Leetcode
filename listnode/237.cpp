#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <memory>

using namespace std;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode * next) : val(x), next(next){}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode * nex = node->next;
        node->val = nex->val;
        node->next = nex->next;
        delete nex;
    }
};

int main(){

}