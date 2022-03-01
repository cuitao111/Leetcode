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
首先考虑使用map保存节点，使用map.count()判断是否遍历过
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *, int> mp;
        ListNode * p = head;
        while (p != nullptr)
        {
            if(mp.count(p)){
                return true;
            }
            mp.insert(p);
            p = p->next;
        }
        return false;

    }
};


int main(){

}
