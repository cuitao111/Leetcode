#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode(int x): val(x), next(NULL){}
};

/*
压入vector中处理
*/

class Solution{
public:
    bool isPalindrome(ListNode* head) {
        ListNode * node = head;
        vector<int> nums;
        while (node != nullptr)
        {
            nums.push_back(node->val);
            node = node->next;
        }
        int l = 0, r = nums.size() - 1;
        // 递归判断l - r是否是回文串
        return isPalindromeNums(nums, l, r, true);
        
        
    }


    bool isPalindromeNums(vector<int> nums, int l, int r, bool flag){
        while (l < r)
        {
            if(nums[l] != nums[r]){
                if(!flag){
                    return false;
                }else{
                    //删除l 判断l+1 ~ r是否回文
                    return isPalindromeNums(nums,l + 1, r, false) || isPalindromeNums(nums,l, r - 1, false);
                }
                
            }
            // 相等直接向内部压缩移位
            l++;
            r--;
        }
        // 循环中不返回false即返回true
        return true;
        
    }
};