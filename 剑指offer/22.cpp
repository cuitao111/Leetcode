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
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution{
public:
    ListNode * getKthFromEnd(ListNode * head, int k){
        ListNode * node1 = head;
        ListNode * node2 = head;
        for(int i = 0; i < k; i++){
            node1 = node1->next;
        }

        // node1移动n-1刚好达到null
        while (node1 != nullptr)
        {
            node1 = node1->next;
            node2 = node2->next;
        }
        return node2;
    
    }
};



