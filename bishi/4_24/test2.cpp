#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct ListNode {
    int val;
	struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param a ListNode类vector 指向每段碎片的开头
     * @return ListNode类
     */
    ListNode* solve(vector<ListNode*>& a) {
        // write code here
        int n = a.size();
        ListNode * dummy = new ListNode(0);
        ListNode * res = nullptr;
        int min = -1;
        for(int i = 0; i < n; i++){
            ListNode * node = dummy;
            ListNode * cur = a[i];
            while(node->next != nullptr && node->next->val != cur->val){
                // 从合并后的头节点向后找，找到相同的节点
                node = node->next;
            }
            while(node->next != nullptr && cur != nullptr){
                node = node->next;
                cur = cur->next;
            }
            cout << (node->next == nullptr|| cur->val != dummy->next->val) << endl;
            // node先结束
            if(node->next == nullptr || cur->val != dummy->next->val){
                node->next == cur;
            }
            // node->next = node->next == nullptr? cur : node->next;
            
            // cur向后找到dummy->next
            while(cur->next != nullptr && cur->next->val != dummy->next->val){
                cur = cur->next;
            }
            if(cur->next != nullptr){
                // 找到环， 执行cur->next = dummy->next构成环
                cur->next = dummy->next;
                node = dummy;
                min = cur->val;
                res = cur;
                while(node->next != cur){
                    if(min > node->next->val){
                        min = node->next->val;
                        res = node;
                    }
                    node = node->next;
                }
                if(res == cur){
                    // cur为最小
                    node->next ==nullptr;
                    return cur;
                }
                ListNode * ret = res->next;
                res->next == nullptr;
                return ret;
            }
        }
        return nullptr;
    }
};


int main(){
    vector<int> a1{1,2,3};
    ListNode * dummy1 = new ListNode(0);
    ListNode * node1 = dummy1;
    for(int i = 0; i < a1.size(); i++){
        ListNode* node = new ListNode(a1[i]);
        node1->next = node;
        node1 = node;
    }
    vector<int> a2{2,3,4};
    ListNode * dummy2 = new ListNode(0);
    ListNode * node2 = dummy2;
    for(int i = 0; i < a2.size(); i++){
        ListNode* node = new ListNode(a2[i]);
        node2->next = node;
        node2 = node;
    }
    vector<int> a3{4,1};
    ListNode * dummy3 = new ListNode(0);
    ListNode * node3 = dummy3;
    for(int i = 0; i < a3.size(); i++){
        ListNode* node = new ListNode(a3[i]);
        node3->next = node;
        node3 = node;
    }
    vector<ListNode *> a;
    a.push_back(dummy1->next);
    a.push_back(dummy2->next);
    a.push_back(dummy3->next);
    Solution * solu = new Solution();
    ListNode * node = solu->solve(a);
    
}