#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <memory>
#include <queue>
#include <list>

using namespace std;


class Solution {
public:
    int findTarget(vector<int>& nums, int head, int tail, int target){
        int mid = head + (tail - head) / 2;
        if(nums[mid] == target){
            return mid;
        }
        if(head == tail && nums[head] != target){
            return -1;
        }
        if(tail == head + 1){
            // 只有两个元素
            if(nums[tail] != target){
                return -1;
            }else{
                return tail;
            }
        }
        if(nums[mid] < nums[head]){
            if(target >= nums[mid] && target < nums[head]){
                // 在右侧区域查找 
                return findTarget(nums, mid, tail, target);
            }else{
                return findTarget(nums, head, mid, target);
            }
        }else{
            if(target <= nums[mid] && target >= nums[head]){
                // 左侧找
                return findTarget(nums, head, mid, target);
            }else{
                return findTarget(nums, mid, tail, target);
            }
        }
    }

    int search(vector<int>& nums, int target) {
        return findTarget(nums, 0, nums.size() - 1, target);
    }
};

int main(){
    Solution * solu = new Solution();
    vector<int> nums{1,3,5};
    int res = solu->search(nums, 1);
    cout << res << endl;
}