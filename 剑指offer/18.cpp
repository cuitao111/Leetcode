#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <memory>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head == nullptr){
            return head;
        }
        if(head->val == val){
            return head->next;
        }

        ListNode * p = head;

        while(p->next != nullptr){
            if(p->next->val == val){
                p->next = p->next->next;
                break;
            }
            p = p->next;
        }
        return head;
    }
};

int main(){

}