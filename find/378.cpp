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

/* 二分需要判定的点
// 选择左右区间的等号时判定 何处mid+1 or mid - 1

[-5, - 4]
(l + r) / 2 = -4 绝对值小的
l +(r -l ) /2 = -5 两个值靠左的
 */

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        if(m == 0){
            return 0;
        }
        int n = matrix[0].size();
        int l = matrix[0][0];
        int r = matrix[m -1][n -1];
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            
            int nums = findNumsLessK(matrix, mid);
            // 退出前一次状态一定为(i, i+1) mid == 1
            // 当刚好nums = k时
            // 
            if(nums < k){
                l = mid + 1 ;
            }else{
                r = mid;
            }

        }
        return l;
        
    }

    int findNumsLessK(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        // 找出小于mid的数有几个
        // 从左下角开始
        int i = m - 1, j = 0;
        int res = 0;
        while (i >=0 && j < n){
            if(matrix[i][j] <= k){
                // 如果小于k右移,同时计算该列有多少个值小于k
                j++;
                res += (i + 1);
            }else{
                i--;
            }
        }
        
        return res;
        
    }
};

