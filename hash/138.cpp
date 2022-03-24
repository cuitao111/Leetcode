#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <memory>
#include <queue>
#include <list>
#include <numeric>

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

    unordered_map<Node* , Node*> mp;
    Node* copyRandomList(Node* head) {
        if(head == nullptr){
            return nullptr;
        }
        if(!mp.count(head)){
            Node * node = new Node(head->val);
            mp[head] =  node;
            node->next = copyRandomList(head->next);
            node->random = copyRandomList(head->random);
        }

        return mp[head];
    }
};