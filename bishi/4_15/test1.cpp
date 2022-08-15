#include <iostream>
 using namespace std;
struct ListNode{
    int val;
    ListNode * next;
    ListNode(int x):val(x), next(NULL){}
};

ListNode * rotateLeft(ListNode * head, int k){
    if(k == 0|| head == nullptr || head->next == nullptr){
        return head;
    }
    int n = 1;
    ListNode * cur = head;
    while(cur->next != nullptr){
        cur = cur->next;
        n++;
    }
//     n为长度
    int add = k % n;
    if(add == n){
        return head;
    }
    cur->next = head;
    while(add > 0){
        cur = cur->next;
        add--;
    }
//     cur移动到尾部 cur next变为头
    ListNode * res = cur->next;
    cur->next = nullptr;
    return res;
    
}


int main(){
    ListNode * dummy = new ListNode(0);
    ListNode * curNode = dummy;
    int n, cur,k;
    cin >> n;
    for(int i = 0; i  < n; i++){
        cin >> cur;
        ListNode *  node = new ListNode(cur);
        curNode->next = node;
        curNode = node;
    }
    cin >> k;
    ListNode * res = rotateLeft(dummy->next, k);
    while(res!= nullptr){
        cout << res->val;
        res = res->next;
    }
}