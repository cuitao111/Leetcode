#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <memory>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

/*
构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新 节点组成，
其中每个新节点的值都设为其对应的原节点的值。新节点的 next 指针
和 random 指针也都应指向复制链表中的新节点，
并使原链表和复制链表中的这些指针能够表示相同的链表状态。
复制链表中的指针都不应指向原链表中的节点 。

需要考虑链表指针成员建立的顺序

如果链表很长，而第一个节点的random节点偏靠后，不能一直保留该节点
知道有节点的next指向该节点

先建立next关系，使用map表示每个节点的random在列表中的位置，
第二遍建立random指针，从头找map.val个节点连接，重复较多

链表中可能出现相同val，不能用val建立关系
使用vector<Node *>



回溯+哈希表

迭代+节点拆分
对于链表 A→B→C
可以将其拆分为 A→A ′ →B→B ′ →C→C ′

先将拷贝节点插入到原节点之后，共用random 

链表长度变为2n，更改新节点的random为原random之后节点
注意判断null

恢复原节点
建立新节点，判断null，否则出现null->next

*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // 第一遍遍历head将原node压入vector，
        // 建立新链表节点以及next关系
        if(head == nullptr){
            return  head;
        };
        Node * p = head;
        Node * dummyHead = new Node(0);
        Node * q = dummyHead;
        
        while (p != nullptr)
        {
            // 建立next的关系
            Node * node = new Node(p->val);
            q->next = node;
            q = node;
            p = p->next;
        }

        // 第二遍建立random关系
        p = head; //source
        q = dummyHead->next;
        Node * node1 = head;
        Node * node2 = dummyHead->next;
        while (p != nullptr)
        {
            // 首先定位node1 2到两个链表的头节点
            node1 = head;
            node2 = dummyHead->next;
            // node1和node2同步,pq同步
            while (node1 != p->random)
            {
                node1 = node1->next;
                node2 = node2->next;
            }
            q->random = node2;
            
            p = p->next;
            q = q->next;

        }
        return dummyHead->next;
        
    }
};


int main(){

}