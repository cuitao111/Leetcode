#include <iostream>

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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node * node = head;
        // 构建next关系
        while(node != nullptr){
            Node * newnode = new Node(node->val);
            newnode->next = node->next;
            node->next = newnode;
            node = node->next->next;
        }
        // 构建random关系
        node = head;
        while(node != nullptr){
            if(node->random != nullptr){
                node->next->random = node->random->next;
            }
            node = node->next->next;
        }
        // 拆解原列表
        node = head;
        Node * nextnode = node->next;
        Node * dummy = node->next;
        while(nextnode->next != nullptr){

            node->next = node->next->next;
            nextnode->next = nextnode->next->next;
            node = node->next;
            nextnode = nextnode->next;
        }
        return dummy;
    }
};

