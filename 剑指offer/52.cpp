#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <memory>

using namespace std;

/*
从尾部向前找


快慢指针


哈希集合
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode *> a,b;
        ListNode * p = headA;
        while (p != nullptr)
        {
            a.push(p);
            p = p->next;
        }

        p = headB;
        while (p != nullptr)
        {
            b.push(p);
            p = p->next;
        }

        ListNode * common = nullptr;

        while (!a.empty() && !b.empty())
        {
            ListNode * eleA = a.top();
            ListNode * eleB = b.top();
            if(eleA != eleB){
                break;
            }
            common = a.top();
            a.pop();
            b.pop();
        }

        if(a.empty()){
            return headA;
        }else if(b.empty()){
            return headB;
        }

        return common;

    }
};


int main(){
    Solution * solu  = new Solution();
    vector<int> a{4,1,8,4,5};
    vector<int> b{5,0,1,8,4,5};
    ListNode * headA = new ListNode(0);
    ListNode * headB = new ListNode(0);
    ListNode * head = headA;
    for(auto it = a.begin(); it != a.end(); it++){
        ListNode * node = new ListNode(*it);
        head->next = node;
        head = node;
    }
    head = headB;
    for(auto it = b.begin(); it != b.end(); it++){
        ListNode * node = new ListNode(*it);
        head->next = node;
        head = node;
    }

    ListNode * res = solu->getIntersectionNode(headA->next, headB->next);

}