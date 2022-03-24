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
    ListNode * next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode * next): val(x), next(next){}
};

/*
k--,直到0
如果中途遇到null且k>0 最后不足k的链表正序

先判断后续是否满足，k长度。每次递归都需要判断，时间耗费多

拆分，先判断后续是否满足k长度，再调用子函数交换k个节点（V）

链表逆序方法 ***
*/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(head == nullptr){
            return head;
        }
        // 如果后续长度大于k，交换
        ListNode * pregroup = new ListNode(0);
        ListNode * prebeforere = nullptr;
        ListNode * nex = nullptr;
        pregroup->next = head;
        ListNode * tail = findTailK(pregroup, k);
        ListNode * ans = pregroup;
        while(tail != nullptr){
            // 存储排序之前的头节点前一个节点，用于下一次循环的输入
            prebeforere = pregroup->next;
            nex = tail->next;
            tie(prebeforere, tail) = swapgroup(prebeforere, tail);
            // 将头尾重新接入链表
            pregroup->next = prebeforere;
            tail->next = nex;
            pregroup = tail;
            // 从更新之后的pregroup向后找k个节点
            tail = findTailK(tail, k);
        }
        return ans->next;

    }
    // 递归实现交换k个值,一个值与一组链表交换需要知道，组链表的头尾
    pair<ListNode*, ListNode*> swapgroup(ListNode * head, ListNode * tail){
        ListNode * prev = tail->next;
        ListNode * p = head;
        // 按顺序依次添加到prev前
        while (prev != tail)
        {
            // 记录nex，用作下一次的p
            ListNode * nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }
        return {tail, head};
    }

    // 如果head之后长度大于k，返回true
    ListNode * findTailK(ListNode * head, int k){
        ListNode * p = head;
        // 临界值，当k=0时 刚好p=null
        while(k > 0 && p != nullptr){
            p = p->next;
            k--;
        }
        if(k > 0){
            return nullptr;
        }else{
            return p;
        }
    }
};

int main(){
    Solution * solu = new Solution();
    vector<int> nums{1,2,3,4,5};
    int k = 2;
    ListNode * pre = new ListNode(0);
    ListNode * head = pre;
    for(auto it = nums.begin(); it != nums.end();it++){
        ListNode * node = new ListNode(*it);
        head->next = node;
        head = head->next;
    }
    
    ListNode * h = solu->reverseKGroup(pre->next, k);

    while (h != nullptr)
    {
        cout << h->val << endl;
        h = h->next;
    }
    
}

