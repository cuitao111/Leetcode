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
两个方向执行二分
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0){
            return false;
        }
        int n = matrix[0].size();
        for(auto & line : matrix){
            // 在line寻找target
            int l = 0, r = n;
            while(l < r){
                int mid = l + (r -l) / 2;
                if(line[mid] == target){
                    return true;
                }
                if(line[mid] >= target){
                    r = mid;
                }else{
                    l = mid + 1;
                }
            }
        }
        return false;
        
    }
};

int main(){
    Solution * solu =new Solution();

}


