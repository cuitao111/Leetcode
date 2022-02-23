#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <memory>

using namespace std;

/*
模拟
*/


struct ListNode
{
    int val;
    ListNode * next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode * next) : val(0), next(next){}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 题中已经说明非空
        ListNode * node1 = l1;
        ListNode * node2 = l2;
        // 进位
        int innum = 0;
        // 当前为和
        int sum = 0;
        ListNode * res = new ListNode(0);
        ListNode * p = res;
        while(node1 != nullptr && node2 != nullptr){
            int x = node1->val;
            int y = node2->val;
            sum = x + y + innum;
            innum = sum / 10;
            ListNode * node = new ListNode(sum % 10);
            p->next = node;
            p = node;
            node1 = node1->next;
            node2 = node2->next;
        }

        if(node1 == nullptr && node2 == nullptr){
            if(innum != 0){
                p->next = new ListNode(innum);
            }
            return res->next;
        }else if(node1 == nullptr){
            while (node2 != nullptr)
            {
                sum = innum + node2->val;
                innum = sum / 10;
                ListNode * node = new ListNode(sum % 10);
                p->next = node;
                p = node;
                node2 = node2->next;
            }
        }else{
            while (node1 != nullptr)
            {
                sum = innum + node1->val;
                innum = sum / 10;
                ListNode * node = new ListNode(sum % 10);
                p->next = node;
                p = node;
                node1 = node1->next;
            }
        }
        if(innum != 0){
            p->next = new ListNode(innum);
        }
        return res->next;
    }
};

int main(){

}