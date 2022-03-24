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

/*
算法的时间复杂度应该为 O(log (m+n)) 。
递归
二分查找两个指针
关键思路：
中位数位置确定 k
两个数组每次平均找出k 个值
因为是有序数组因为只从大到小找出了K个值
找到的两个值不可能都大于k这样填不满 k
也就是至少有一个值位置小于k


int newIndex1 = min(index1 + k / 2 - 1, m - 1);
int newIndex2 = min(index2 + k / 2 - 1, n - 1);
int pivot1 = nums1[newIndex1];
int pivot2 = nums2[newIndex2];
if (pivot1 <= pivot2) {
    k -= newIndex1 - index1 + 1;
    index1 = newIndex1 + 1;
}
else {
    k -= newIndex2 - index2 + 1;
    index2 = newIndex2 + 1;
}
不需要重新调用，只需要再循环里重复更新index


*/

class Solution {
public:
    double getKElement(vector<int> & nums1, vector<int> &nums2, 
    int p1, int p2, int indexOfMid){
        int len1 = nums1.size();
        int len2 = nums2.size();
        if(p1 >= nums1.size()){
            return nums2[p2 +indexOfMid - 1];
        }
        if(p2 >= nums2.size()){
            return nums1[p1 +indexOfMid - 1];
        }
        if(indexOfMid == 1){
            return 1.0 * min(nums1[p1], nums2[p2]);
        }
        int halfOfMid = indexOfMid / 2 - 1;
        // 先看是否越界
        int position1 = min(p1 + halfOfMid, len1 - 1);
        int position2 = min(p2 + halfOfMid, len2 - 1);
        if(nums1[position1] <= nums2[position2]){
            // 删除p1 -positon1位置的元素
            int numsOfDel = position1 - p1 + 1;
            return getKElement(nums1, nums2, position1 + 1, p2, indexOfMid - numsOfDel); 
        }else{
            int numsOfDel = position2 - p2 + 1;
            return getKElement(nums1, nums2, p1, position2 + 1, indexOfMid - numsOfDel); 
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int indexOfMid;
        if((len1 + len2) % 2 == 0){
            indexOfMid = (len1 + len2) / 2;
            // 4的中位数下为1 和 2 ，需要找第2 和 3个数
            int left = getKElement(nums1, nums2, 0, 0, indexOfMid);
            int right = getKElement(nums1, nums2, 0, 0, indexOfMid + 1);
            return 0.5 * (left + right);
        }else{
            indexOfMid = (len1 + len2) / 2 + 1;
            // 5的中位数下标为 2 = 5/2，需要找第三个值
            return 1.0 *getKElement(nums1, nums2, 0, 0, indexOfMid);
        }
        // 需要传入递归函数的参数 nums1 nums2 两个指针 indexOfMid
        
        
    }
};

int main(){
    Solution * solu = new Solution();
    vector<int> nums1{4};
    vector<int> nums2{1,2,3,5,6};
    double res = solu->findMedianSortedArrays(nums1,nums2);
    cout << res << endl;
}