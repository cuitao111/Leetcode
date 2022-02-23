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

/*
建立一个头节点 每次插入头节点和res->next之间
并设定一个节点存放下一个需要入链的节点
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * res = new ListNode(0);
        ListNode * nex = head;
        while (nex != nullptr)
        {
            // nex插入res和res->next之间
            ListNode * temp = nex->next;
            nex->next = res->next;
            res->next = nex;
            nex = temp;
        }
        return res->next;
    }
};


int main(){
    cout << 1 << endl;

}