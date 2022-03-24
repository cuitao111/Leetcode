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
    ListNode() : val(0), next{nullptr}{}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode * next) : val(x),next(next){}

};

class  Solution
{

public:
    ListNode * swapPair(ListNode * head){
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode * ans = nullptr;
        ListNode * p = head;
        // pre记录交换两节点前面一个节点，需要对其的next更改
        ListNode * pre = nullptr;
        // 成对交换
        while (p != nullptr && p->next != nullptr)
        {
            ListNode * temp = p->next;
            // 前一个节点连接到后面节点
            p->next = p->next->next;
            // 后节点插入前节点
            temp->next = p;
            if(pre != nullptr){
                pre->next = temp;
            }else{
                ans = temp;
            }
            pre = p;
            p = p->next;
        }
        return ans;
        
    }
};


int main(){

}