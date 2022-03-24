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

/*
与数组不同无法从后向前遍历

计算长度，将前一半压入stack

1、复制到vector中使用两个指针
2、快慢指针
找到中间节点，反转链表，双指针判断是否相同
3、递归
从frontpoint向后递归调用，直到最后到null返回true，开始比较
此时frointpoint指向第一个点，current指向最后一个点
相同frontpouint向后移动， current由与函数递归调用返回上一个个点
继续比较
front移动到current之后？
*/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return true;
        }
        ListNode * p = head;
        int len = 0;
        // 找到一半节点用快慢指针   
        while(p != nullptr){
            len++;
            p = p->next;
        }
        
        p = head;
        stack<int> stk;
        for(int i = 0; i < len / 2; i++){
            stk.push(p->val);
            p = p->next;
        }
        // 每次压入之后已经指向下一个节点
        if(len % 2 != 0){
            p = p->next;
        }else{
            p = p;
        }

        while (p != nullptr)
        {
            if(stk.top() != p->val){
                return false;
            }
            stk.pop();
            p = p->next;
        }

        if(stk.empty()){
            return true;
        }
        return false;
        
        
    }
};

int main(){
    Solution * solu = new Solution();
    vector<int> nums{1,2,2,1};
    ListNode * head = new ListNode(0);
    ListNode * p = head;
    for(auto it = nums.begin(); it != nums.end(); it++){
        ListNode * node = new ListNode(*it);
        p->next = node;
        p = node;
    }
    bool res = solu->isPalindrome(head->next);
    cout << res << endl;
}