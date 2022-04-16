#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
反转链表，输出
栈递归
*/

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        if(head == nullptr){
            return {};
        }
        vector<int> a = reversePrint(head->next);
        a.push_back(head->val);
        return a;
    }
};


int main(){
    Solution * solu = new Solution();
    vector<int> nums{1,2,3};
    ListNode * dummyhead = new ListNode(0);
    ListNode * node = dummyhead;
    for(auto & num: nums){
        ListNode* newnode = new ListNode(num);
        node->next = newnode;
        node = newnode;
    }
    vector<int> res = solu->reversePrint(dummyhead->next);
    cin.get();
}