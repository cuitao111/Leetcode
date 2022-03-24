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

插入排序时间复杂度O(n^2)

每次从链表中取出一个值进行与前面链表进行排序



class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr){
            return head;
        }
        ListNode * res = new ListNode(0);
        ListNode * p = res;
        ListNode * q = head;
        ListNode * cur = head;
        res->next = cur;
        cur = cur->next;
        while (cur != nullptr)
        {
            p = res;
            // p向后移动直到找到大于cur->val的节点
            while (p->next != cur->next && p->next->val <= cur->val)
            {
                p = p->next;   
            }
            // 判断是否达到q
            if(p->next == cur->next){
                q = q->next;
                cur = cur->next;
            }else{
                // 将cur插入p前
                ListNode * node = cur;
                cur = cur->next;
                node->next = p->next;
                p->next = node;
                q->next = cur;
            }
            
        }
        return res->next;

    }
};

*/

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return sortList(head, nullptr);
    }

    ListNode * sortList(ListNode * head, ListNode * tail){
        if (head == nullptr) {
            return head;
        }
        // 每次遇到两个节点的情况，中间插入一个null
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }
        ListNode * fast = head;
        ListNode * slow = head;
        while(fast->next != tail){
            fast = fast->next;
            slow = slow->next;
            if(fast != nullptr){
                fast = fast->next;
            }
        }

        ListNode * mid =  slow;
        // 是否需要将第一段中间填补null，若不填补
        // merege时需要传入四个节点
        // 对前后两端分别排序
        return merge(sortList(head, mid), sortList(mid, tail));
    }


    ListNode * merge(ListNode * list1, ListNode * list2){
        ListNode * dummyHead = new ListNode(0);
        ListNode * temp = dummyHead, * temp1 = list1, * temp2 = list2;
        // 保证list2的长度与list1相同或为list1长度减一
        while (temp1 != nullptr && temp2 != nullptr)
        {
            if(temp1->val < temp2->val){
                temp->next = temp1;
                temp1 = temp1->next;
                
            }else{
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1 != nullptr) {
            temp->next = temp1;
        } else if (temp2 != nullptr) {
            temp->next = temp2;
        }
        return dummyHead->next;

    }
};


int main(){
    Solution * solu = new Solution();
    vector<int> nums{-1,5,3,4,0};
    ListNode * head = new ListNode(0);
    ListNode * p = head;
    for(int i = 0; i < nums.size(); i++){
        ListNode * node = new ListNode(nums[i]);
        p->next = node;
        p = node;
    }
    ListNode * res = solu->sortList(head->next);
    while (res != nullptr)
    {
        cout << res->val << endl;
        res = res->next;
    }
    

}