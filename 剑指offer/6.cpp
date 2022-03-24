#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <memory>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> ans;
        // 如果为空
        if(head == nullptr){
            return ans;
        }

        ListNode * point = head;

        while (point->next != nullptr)
        {
            ans.push_back(point->val);
            point = point->next;
        }

        reverse(ans.begin(), ans.end());

        return ans;
        
    }
};

int main(){
    Solution * solu = new Solution();
    
}