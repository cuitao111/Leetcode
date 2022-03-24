#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <memory>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode * dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode * p = dummyHead;
        while (p->next != nullptr && p->next->next != nullptr)
        {
            ListNode * node1 = p->next;
            ListNode * node2 = p->next->next;

            node1->next = node2->next;
            p->next = node2;
            node2->next = node1;
            p = p->next->next;
        }
        return dummyHead->next;
        
    }
};