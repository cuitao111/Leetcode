#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <memory>

using namespace std;

/*
分治

优先队列
*/

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int sizeOfList = lists.size();
        if(sizeOfList == 0){
            return nullptr;
        }
        int minVal = 0,minindex = -1;
        bool fisrt = true;
        // 遍历一遍vector看是否全部为nullptr,并将最小val存入minVal
        for(int i = 0; i < sizeOfList; i++){
            if(lists[i] != nullptr){
                if(fisrt){
                    minVal = lists[i]->val;
                    minindex = i;
                    fisrt = false;
                }else{
                    if(lists[i]->val < minVal){
                        minVal = lists[i]->val;
                        minindex = i;
                    } 
                }
            }
        }
        // 如果minVal minindex fisrt没有变动
        if(fisrt && minVal == 0 && minindex == -1){
            return nullptr;
        }
        // 从链表中找到最小值对应节点node1 
        ListNode * node = lists[minindex];
        // 更新对应位置的链表节点
        lists[minindex] = node->next;
        // 把node1的next连接到mergeLists()
        node->next = mergeKLists(lists);
        return node;  
    }
};

int main(){
    vector<int> a{1,4,5}, b{1,3,4}, c{2,6};
    ListNode * headA = new ListNode(0);
    ListNode * headB = new ListNode(0);
    ListNode * headC = new ListNode(0);
    ListNode * p1 = headA;
    ListNode * p2 = headB;
    ListNode * p3 = headC;
    for(int i = 0; i < a.size(); i++){
        ListNode * node = new ListNode(a[i]);
        p1->next = node;
        p1 = node;
    }
    for(int i = 0; i < b.size(); i++){
        ListNode * node = new ListNode(b[i]);
        p2->next = node;
        p2 = node;
    }
    for(int i = 0; i < c.size(); i++){
        ListNode * node = new ListNode(c[i]);
        p3->next = node;
        p3 = node;
    }

    vector<ListNode *> lists(3);
    lists[0] = headA->next;
    lists[1] = headB->next;
    lists[3] = headC->next;

    Solution * solu = new Solution();
    ListNode * res = solu->mergeKLists(lists);


}