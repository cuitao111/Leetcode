#include <vector>
#include <iostream>

using namespace std;

/*
[10,1,10,10,10]
[10,10,10,1,10]
l r mid关系相同 但无法判断左右子集
画出折线图

相似题目 153 154
*/

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int n = numbers.size();
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if(numbers[mid] < numbers[r]){
                // 左侧 需要将mid包含在内
                r = mid;
            }else if(numbers[mid] > numbers[r]){
                l = mid + 1;
            }else{
                r = r - 1;
            }
        }
        return numbers[l];
    }
};

int main(){
    Solution * solu = new Solution();
    vector<int> nums{1,3,5};
    cout << solu->minArray(nums) << endl;
    cin.get();
}